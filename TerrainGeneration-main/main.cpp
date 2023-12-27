// Used noise: https://github.com/stegu/perlin-noise
#include "glwnd.h"
#include "gl_ext_loader.h"

#include <vector>
#include "world_generator.h"
#include "camera.h"
//#include"noise/noise1234.h"
#include "SimplexNoise.h"

INT Width, Height;
double last_time = 0.;
float scales = 2.00f;

std::vector<vec3> vertices;
std::vector<vec3> colors;
std::vector<unsigned int> indices;
unsigned int number_of_indices;
bool buttons[2048];

bool is_filled = false;

CCamera camera(45.f, vec3(0.f, 10.f, 0.f));

unsigned int vao, vbo, ebo;

double TimeGetSeconds()
{
	LARGE_INTEGER frequency, time;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&time);
	return time.QuadPart / (double)frequency.QuadPart;
}

// Add new function to enable color arrays
void enable_color_arrays()
{
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, sizeof(vec3), &colors);
}

void fn_draw()
{
	double current_time = TimeGetSeconds();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	camera.UpdateCameraState(GetStruct()->h_window);
	camera.Look();
	camera.Move(buttons, 0.1f);

	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1);
	glEnd();

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	glVertexPointer(3, GL_FLOAT, 0, NULL);
	//glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	glDrawElements(GL_TRIANGLES, number_of_indices, GL_UNSIGNED_INT, NULL);
	//printf("%d\n", number_of_indices);

	//int error = glGetError();
	//if (error != GL_NO_ERROR) {
	//	printf("GL ERROR: %s\n", gluErrorString(error));
	//}

	int currfps = (int)1.f / (current_time - last_time);
	static int minfps = 1000, maxfps = 1;
	minfps = min(minfps, currfps);
	maxfps = max(maxfps, currfps);
	if (!(GetTickCount() % 10))
		printf("curr FPS: %d  (min: %d | max: %d)      \r", currfps, minfps, maxfps);

	last_time = current_time;
}

void fn_window_resize(HWND hWnd, int width, int height)
{
	if (!height)
		height = 1;

	Width = width;
	Height = height;
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, width / (double)height, 0.1, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void fn_mousemove(HWND hWnd, int x, int y)
{
}

void fn_mouseclick(HWND hWnd, int x, int y, int button, int state)
{
}

void fn_charinput(HWND hWnd, char symbol)
{
}

//https://docs.microsoft.com/ru-ru/windows/win32/inputdev/wm-keydown
void fn_keydown(HWND hWnd, INT state, WPARAM wparam, LPARAM lparam)
{
	INT key = (INT)wparam;
	buttons[key] = state;
	if (state == KEY_DOWN) {
		switch (key) {
		case 27:
			exit(0); //close program
			break;

		case VK_F1:
			camera.SetActive(!camera.IsActive());
			break;

		case VK_F2:
			is_filled = !is_filled;
			glPolygonMode(GL_FRONT_AND_BACK, is_filled ? GL_FILL : GL_LINE);
			break;
        case VK_F3:
			// Increase terrain height
			scales *= 1.1f;  // Adjust the scaling factor as needed
			break;

		case VK_F4:
			// Decrease terrain height
			scales *= 0.9f;  // Adjust the scaling factor as needed
			break;

		case VK_F5:
			// Toggle color dependency on height
			//vertex_generation_filter.colorDependency = !vertex_generation_filter.colorDependency;
			break;
		}
	}
}

#pragma region MYALG
void generate_triangles_plane_no_eb(std::vector<vec3> &dest_verts, float xpos, float ypos, float zpos, float width_x, float width_y, float step)
{
	float half_width_x = width_x / 2.f;
	float half_width_y = width_y / 2.f;
	for (int x = xpos - half_width_x; x < xpos + half_width_x; x += step) {
		for (int z = zpos - half_width_y; z < zpos + half_width_y; z += step) {
			//создаем первый треугольник
			dest_verts.push_back(vec3((float)x, ypos, (float)z));
			dest_verts.push_back(vec3((float)x + step, ypos, (float)z));
			dest_verts.push_back(vec3((float)x, ypos, (float)z + step));

			//создаем второй треугольник
			dest_verts.push_back(vec3((float)x, ypos, (float)z + step));
			dest_verts.push_back(vec3((float)x + step, ypos, (float)z + step));
			dest_verts.push_back(vec3((float)x + step, ypos, (float)z));
		}
	}
}

void generate_triangles_plane(std::vector<vec3> &dest_verts, std::vector<unsigned int> &dest_indices,
	float xpos, float ypos, float zpos,
	float width_x, float width_y, float step)
{
	vec3 p1, p2, p3;
	int indice1, indice2;
	float half_width_x = width_x / 2.f;
	float half_width_y = width_y / 2.f;
	for (int x = xpos - half_width_x; x < xpos + half_width_x; x += step) {
		for (int z = zpos - half_width_y; z < zpos + half_width_y; z += step) {
			
			//создаем первый треугольник
			p1 = vec3((float)x, ypos, (float)z);
			dest_verts.push_back(p1);
			dest_indices.push_back(dest_verts.size() - 1);

			p2 = vec3((float)x + step, ypos, (float)z);
			dest_verts.push_back(p2);
			indice1 = dest_verts.size() - 1;
			dest_indices.push_back(indice1);

			p3 = vec3((float)x, ypos, (float)z + step);
			dest_verts.push_back(p3);
			indice2 = dest_verts.size() - 1;
			dest_indices.push_back(indice2);

			//создаем второй треугольник
			dest_indices.push_back(indice1);
			dest_indices.push_back(indice2);
                                                                                                                                                  
			p2 = vec3((float)x + step, ypos, (float)z + step);
			dest_verts.push_back(p2);
			dest_indices.push_back(dest_verts.size() - 1);
		}
	}
}

//наполовину оптимизированный вариант
//сокращаются вершины в соприкасающихся гипотенузах двух треугольников
void generate_triangles_plane_noise(SimplexNoise &sn, std::vector<vec3> &dest_verts, std::vector<unsigned int> &dest_indices,
	float xpos, float ypos, float zpos,
	float width_x, float width_y, float step, void (*vertex_filter_fn)(vec3 &vertex))
{
	vec3 p1, p2, p3;
	int indice1, indice2;
	float half_width_x = width_x / 2.f;
	float half_width_y = width_y / 2.f;
	for (int x = xpos - half_width_x; x < xpos + half_width_x; x += step) {
		for (int z = zpos - half_width_y; z < zpos + half_width_y; z += step) {

			//создаем первый треугольник
			p1 = vec3((float)x, ypos, (float)z);
			vertex_filter_fn(p1);
			dest_verts.push_back(p1);
			dest_indices.push_back(dest_verts.size() - 1);

			p2 = vec3((float)x + step, ypos, (float)z);
			vertex_filter_fn(p2);
			dest_verts.push_back(p2);
			indice1 = dest_verts.size() - 1;
			dest_indices.push_back(indice1);

			p3 = vec3((float)x, ypos, (float)z + step);
			vertex_filter_fn(p3);
			dest_verts.push_back(p3);
			indice2 = dest_verts.size() - 1;
			dest_indices.push_back(indice2);

			//создаем второй треугольник
			dest_indices.push_back(indice1);
			dest_indices.push_back(indice2);

			p2 = vec3((float)x + step, ypos, (float)z + step);
			vertex_filter_fn(p2);
			dest_verts.push_back(p2);
			dest_indices.push_back(dest_verts.size() - 1);
		}
	}
}

//полностью оптимизированная функция генерации сетки с шумом
void generate_triangles_plane_noise2(std::vector<vec3> &dest_verts, std::vector<unsigned int> &dest_indices,
	int xpos, int ypos, int zpos,
	int width_x, int width_z, int step, void(*vertex_filter_fn)(vec3 &vertex))
{
	vec3 p1, p2, p3;
	int indice0, indice1, indice2;
	int half_width_x = width_x / 2;
	int half_width_z = width_z / 2;

	int min[2], max[2];
	min[0] = xpos - half_width_x;
	min[1] = zpos - half_width_z;
	max[0] = xpos + half_width_x;
	max[1] = zpos + half_width_z;

	int edge_ind[2];
	for (int x = min[0]; x < max[0]; x += step) {
		for (int z = min[1]; z < max[1]; z += step) {
			//создаем первый треугольник
			p1 = vec3(x, ypos, z);
			vertex_filter_fn(p1);
			dest_verts.push_back(p1);
			indice0 = dest_verts.size() - 1;
			dest_indices.push_back(indice0);

			p2 = vec3(x + step, ypos, z);
			vertex_filter_fn(p2);
			dest_verts.push_back(p2);
			indice1 = dest_verts.size() - 1;
			dest_indices.push_back(indice1);

			p3 = vec3(x, ypos, z + step);
			vertex_filter_fn(p3);
			dest_verts.push_back(p3);
			indice2 = dest_verts.size() - 1;
			dest_indices.push_back(indice2);

			//создаем второй треугольник
			dest_indices.push_back(indice1);
			dest_indices.push_back(indice2);
			edge_ind[0] = indice2;

			p2 = vec3(x + step, ypos, z + step);
			vertex_filter_fn(p2);
			dest_verts.push_back(p2);
			edge_ind[1] = dest_verts.size() - 1;
			dest_indices.push_back(edge_ind[1]);

			for (; z < max[1]; z += step) {

			}
		}
	}
}
#pragma endregion

SimplexNoise perlin;

const float frequency = 20.f;
const float frequency_m = 1000.f;

void vertex_generation_filter(vec3 &vertex)
{
	float nx = vertex.x / 1000.f, nz = vertex.z / 1000.f;
	vertex.y = (1.00f *  perlin.noise(1.f *	nx, 1.f *  nz)
		+ 0.50f * perlin.noise(2.f *  nx, 2.f *  nz)
		+ 0.25f * perlin.noise(4.f *  nx, 4.f *  nz)
		+ 0.13f * perlin.noise(8.f *  nx, 8.f *  nz)
		+ 0.06f * perlin.noise(16.f * nx, 16.f * nz)
		+ 0.03f * perlin.noise(32.f * nx, 32.f * nz));
	vertex.y /= (1.00f + 0.50f + 0.25f + 0.13f + 0.06f + 0.03f);
	vertex.y = pow(vertex.y, 1);
	vertex.y *= 300;

	// Compute color based on height
	float normalized_height = (vertex.y + 150.0f) / 300.0f;  // Normalize height to [0, 1]
	vec3 color(0.0f, normalized_height, 0.0f);  // Green color based on height
	colors.push_back(color);
}

//Add this GL functions
void fn_windowcreate(HWND hWnd)
{
	if (!LoadGLExtensions()) {
		printf("Failed to load opengl extensions!\n");
		exit(1);
	}

	RECT rct;
	GetClientRect(hWnd, &rct);
	glViewport(0, 0, (GLsizei)rct.right, (GLsizei)rct.bottom);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, rct.right / (double)rct.bottom, 0.1, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnableClientState(GL_VERTEX_ARRAY);
	camera.SetActive(true);

#pragma region OLDCODE
	//float y = 0.f;
	//for (int x = 0; x < 200; x++) {
	//	for (int z = 0; z < 200; z++) {
	//		vec3 p1, p2, p3;

	//		//y = perlin.noise((float)x / 10.f, (float)z / 10.f);

	//		//создаем первый треугольник
	//		p1 = vec3((float)x, y, (float)z);
	//		//p1.y = perlin.noise((float)p1.x / 10.f, (float)p1.z / 10.f);

	//		p2 = vec3((float)x + 1, y, (float)z);
	//		//p2.y = perlin.noise((float)p2.x / 10.f, (float)p2.z / 10.f);

	//		p3 = vec3((float)x, y, (float)z + 1);
	//		//p3.y = perlin.noise((float)p3.x / 10.f, (float)p3.z / 10.f);

	//		vertices.push_back(p1);
	//		vertices.push_back(p2);
	//		vertices.push_back(p3);
	//		//printf("Tri1( %f %f ) ( %f %f ) ( %f %f ) ", p1.x, p1.z, p2.x, p2.z, p3.x, p3.z);

	//		//создаем второй треугольник
	//		p1 = vec3((float)x, y, (float)z + 1);
	//		//p1.y = perlin.noise((float)p1.x / 10.f, (float)p1.z / 10.f);

	//		p2 = vec3((float)x + 1, y, (float)z + 1);
	//		//p2.y = perlin.noise((float)p2.x / 10.f, (float)p2.z / 10.f);

	//		p3 = vec3((float)x + 1, y, (float)z);
	//		//p3.y = perlin.noise((float)p3.x / 10.f, (float)p3.z / 10.f);

	//		vertices.push_back(p1);
	//		vertices.push_back(p2);
	//		vertices.push_back(p3);
	//		//printf("Tri2( %f %f ) ( %f %f ) ( %f %f )\n", p1.x, p1.z, p2.x, p2.z, p3.x, p3.z);
	//	}
	//}
#pragma endregion

	float ambient[] = { 0.0f, 0.0f, 0.0f, 1.f };
	float diffuse[] = { 0.5f, 0.5f, 0.5f, 1.f };
	float position[] = { 0.f, 100.f, 0.f, 0.f };
	float direction[] = { 0.f, -1.f, 0.f };

	glShadeModel(GL_FLAT);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);

	//generate_triangles_plane_no_eb(vertices, 0.f, 0.f, 0.f, 1000.f, 1000.f, 1.f);
	//generate_triangles_plane(vertices, indices, 0.f, 0.f, 0.f, 100.f, 100.f, 1.f);
	generate_triangles_plane_noise(perlin, vertices, indices, 0.f, 0.f, 0.f, 500.f, 500.f, 1.0f, vertex_generation_filter);
	//generate_triangles_plane_noise2(vertices, indices, 0, 0, 0, 1000, 1000, 1, vertex_generation_filter);

	//create vertex buffer object
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * vertices.size(), vertices.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//create element buffer object
	number_of_indices = indices.size();
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * number_of_indices, indices.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	vertices.clear();
	indices.clear();

	last_time = TimeGetSeconds();
}

void fn_windowclose(HWND hWnd)
{
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
	glDisableClientState(GL_VERTEX_ARRAY);
	exit(0);
}

int main()
{
	create_window("Terrain generation with Perlin noise", __DATE__ __TIME__,
		24,					  //Colors bits
		32,					  //Depth bits
		fn_draw,			  //Draw function
		fn_window_resize,	  //Window resize function
		fn_mousemove,		  //Mouse move function
		fn_mouseclick,		  //Mouse click function
		fn_charinput,		  //Char input function
		fn_keydown,			  //Keydown function
		fn_windowcreate,	  //Window create function
		fn_windowclose,		  //Window close function
		0, 0,
		1280,				  //Window width
		720);				  //Window height
	return 0;
}