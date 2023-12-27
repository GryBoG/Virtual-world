#include "gl_ext_loader.h"

PFNPROCADDR plGetProcAddress;

PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = NULL;
PFNGLTEXIMAGE3DPROC glTexImage3D = NULL;
PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D = NULL;
PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = NULL;

PFNGLACTIVETEXTUREPROC glActiveTexture = NULL;
PFNGLSAMPLECOVERAGEPROC glSampleCoverage = NULL;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D = NULL;
PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = NULL;
PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage = NULL;

PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = NULL;
PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays = NULL;
PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = NULL;
PFNGLPOINTPARAMETERFPROC glPointParameterf = NULL;
PFNGLPOINTPARAMETERFVPROC glPointParameterfv = NULL;
PFNGLPOINTPARAMETERIPROC glPointParameteri = NULL;
PFNGLPOINTPARAMETERIVPROC glPointParameteriv = NULL;
PFNGLBLENDCOLORPROC glBlendColor = NULL;
PFNGLBLENDEQUATIONPROC glBlendEquation = NULL;

PFNGLGENQUERIESPROC glGenQueries = NULL;
PFNGLDELETEQUERIESPROC glDeleteQueries = NULL;
PFNGLISQUERYPROC glIsQuery = NULL;
PFNGLBEGINQUERYPROC glBeginQuery = NULL;
PFNGLENDQUERYPROC glEndQuery = NULL;
PFNGLGETQUERYIVPROC glGetQueryiv = NULL;
PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv = NULL;
PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv = NULL;
PFNGLBINDBUFFERPROC glBindBuffer = NULL;
PFNGLDELETEBUFFERSPROC glDeleteBuffers = NULL;
PFNGLGENBUFFERSPROC glGenBuffers = NULL;
PFNGLISBUFFERPROC glIsBuffer = NULL;
PFNGLBUFFERDATAPROC glBufferData = NULL;
PFNGLBUFFERSUBDATAPROC glBufferSubData = NULL;
PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData = NULL;
PFNGLMAPBUFFERPROC glMapBuffer = NULL;
PFNGLUNMAPBUFFERPROC glUnmapBuffer = NULL;
PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv = NULL;
PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv = NULL;

PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate = NULL;
PFNGLDRAWBUFFERSPROC glDrawBuffers = NULL;
PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate = NULL;
PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate = NULL;
PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate = NULL;
PFNGLATTACHSHADERPROC glAttachShader = NULL;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation = NULL;
PFNGLCOMPILESHADERPROC glCompileShader = NULL;
PFNGLCREATEPROGRAMPROC glCreateProgram = NULL;
PFNGLCREATESHADERPROC glCreateShader = NULL;
PFNGLDELETEPROGRAMPROC glDeleteProgram = NULL;
PFNGLDELETESHADERPROC glDeleteShader = NULL;
PFNGLDETACHSHADERPROC glDetachShader = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = NULL;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = NULL;
PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib = NULL;
PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform = NULL;
PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders = NULL;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation = NULL;
PFNGLGETPROGRAMIVPROC glGetProgramiv = NULL;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = NULL;
PFNGLGETSHADERIVPROC glGetShaderiv = NULL;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = NULL;
PFNGLGETSHADERSOURCEPROC glGetShaderSource = NULL;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = NULL;
PFNGLGETUNIFORMFVPROC glGetUniformfv = NULL;
PFNGLGETUNIFORMIVPROC glGetUniformiv = NULL;
PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv = NULL;
PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv = NULL;
PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv = NULL;
PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv = NULL;
PFNGLISPROGRAMPROC glIsProgram = NULL;
PFNGLISSHADERPROC glIsShader = NULL;
PFNGLLINKPROGRAMPROC glLinkProgram = NULL;
PFNGLSHADERSOURCEPROC glShaderSource = NULL;
PFNGLUSEPROGRAMPROC glUseProgram = NULL;
PFNGLUNIFORM1FPROC glUniform1f = NULL;
PFNGLUNIFORM2FPROC glUniform2f = NULL;
PFNGLUNIFORM3FPROC glUniform3f = NULL;
PFNGLUNIFORM4FPROC glUniform4f = NULL;
PFNGLUNIFORM1IPROC glUniform1i = NULL;
PFNGLUNIFORM2IPROC glUniform2i = NULL;
PFNGLUNIFORM3IPROC glUniform3i = NULL;
PFNGLUNIFORM4IPROC glUniform4i = NULL;
PFNGLUNIFORM1FVPROC glUniform1fv = NULL;
PFNGLUNIFORM2FVPROC glUniform2fv = NULL;
PFNGLUNIFORM3FVPROC glUniform3fv = NULL;
PFNGLUNIFORM4FVPROC glUniform4fv = NULL;
PFNGLUNIFORM1IVPROC glUniform1iv = NULL;
PFNGLUNIFORM2IVPROC glUniform2iv = NULL;
PFNGLUNIFORM3IVPROC glUniform3iv = NULL;
PFNGLUNIFORM4IVPROC glUniform4iv = NULL;
PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv = NULL;
PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv = NULL;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv = NULL;
PFNGLVALIDATEPROGRAMPROC glValidateProgram = NULL;
PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d = NULL;
PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv = NULL;
PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f = NULL;
PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv = NULL;
PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s = NULL;
PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv = NULL;
PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d = NULL;
PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv = NULL;
PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f = NULL;
PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv = NULL;
PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s = NULL;
PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv = NULL;
PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d = NULL;
PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv = NULL;
PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f = NULL;
PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv = NULL;
PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s = NULL;
PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv = NULL;
PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv = NULL;
PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv = NULL;
PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv = NULL;
PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub = NULL;
PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv = NULL;
PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv = NULL;
PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv = NULL;
PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv = NULL;
PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d = NULL;
PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv = NULL;
PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f = NULL;
PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv = NULL;
PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv = NULL;
PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s = NULL;
PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv = NULL;
PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv = NULL;
PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv = NULL;
PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv = NULL;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = NULL;

PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = NULL;
PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = NULL;
PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = NULL;
PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = NULL;
PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = NULL;
PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = NULL;

PFNGLCOLORMASKIPROC glColorMaski;
PFNGLGETBOOLEANI_VPROC glGetBooleani_v;
PFNGLGETINTEGERI_VPROC glGetIntegeri_v;
PFNGLENABLEIPROC glEnablei;
PFNGLDISABLEIPROC glDisablei;
PFNGLISENABLEDIPROC glIsEnabledi;
PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback;
PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback;
PFNGLBINDBUFFERRANGEPROC glBindBufferRange;
PFNGLBINDBUFFERBASEPROC glBindBufferBase;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying;
PFNGLCLAMPCOLORPROC glClampColor;
PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender;
PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender;
PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;
PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv;
PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv;
PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i;
PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i;
PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i;
PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i;
PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui;
PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui;
PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui;
PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui;
PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv;
PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv;
PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv;
PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv;
PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv;
PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv;
PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv;
PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv;
PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv;
PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv;
PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv;
PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv;
PFNGLGETUNIFORMUIVPROC glGetUniformuiv;
PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation;
PFNGLUNIFORM1UIPROC glUniform1ui;
PFNGLUNIFORM2UIPROC glUniform2ui;
PFNGLUNIFORM3UIPROC glUniform3ui;
PFNGLUNIFORM4UIPROC glUniform4ui;
PFNGLUNIFORM1UIVPROC glUniform1uiv;
PFNGLUNIFORM2UIVPROC glUniform2uiv;
PFNGLUNIFORM3UIVPROC glUniform3uiv;
PFNGLUNIFORM4UIVPROC glUniform4uiv;
PFNGLTEXPARAMETERIIVPROC glTexParameterIiv;
PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv;
PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv;
PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv;
PFNGLCLEARBUFFERIVPROC glClearBufferiv;
PFNGLCLEARBUFFERUIVPROC glClearBufferuiv;
PFNGLCLEARBUFFERFVPROC glClearBufferfv;
PFNGLCLEARBUFFERFIPROC glClearBufferfi;
PFNGLGETSTRINGIPROC glGetStringi;
PFNGLISRENDERBUFFERPROC glIsRenderbuffer;
PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
PFNGLISFRAMEBUFFERPROC glIsFramebuffer;
PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D;
PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D;
PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample;
PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer;
PFNGLMAPBUFFERRANGEPROC glMapBufferRange;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
PFNGLISVERTEXARRAYPROC glIsVertexArray;

PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
PFNGLTEXBUFFERPROC glTexBuffer;
PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;
PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName;
PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName;
PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding;

#if defined(_DEBUG) || defined(GLL_FORCE_ERROR_CHECK)
void glloader_checkerror_win32(const char *p_description)
{
	int32_t error = glGetError();
	if (error != GL_NO_ERROR) {
		char buffer[1024];
		const char *p_error_text = (const char *)gluErrorString(error);
		if (!p_error_text)
			p_error_text = "NULL_STRING";

		sprintf_s(buffer, sizeof(buffer), "OpenGL error!\nDescription: %s\nError code: %d\nError string: %s",
			p_description, error, p_error_text);
		if (MessageBoxA(HWND_DESKTOP, "GL error checker", buffer, MB_OKCANCEL) == IDCANCEL) {
			__debugbreak();
			exit(111);
		}
	}
}
#endif

bool GetGLVersion(GLVERSION *pverst)
{
	const char *p_verstr = (const char*)glGetString(GL_VERSION);
	//version not found or error occurred
	if (!p_verstr || !p_verstr[0])
		return false;

	sscanf_s(p_verstr, "%d.%d", &pverst->minor, &pverst->major);
	return true;
}

void LoadGL12Extensions()
{
	glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)plGetProcAddress("glDrawRangeElements");
	glTexImage3D = (PFNGLTEXIMAGE3DPROC)plGetProcAddress("glTexImage3D");
	glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)plGetProcAddress("glTexSubImage3D");
	glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)plGetProcAddress("glCopyTexSubImage3D");
}

void LoadGL13Extensions()
{
	glActiveTexture = (PFNGLACTIVETEXTUREPROC)plGetProcAddress("glActiveTexture");
	glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)plGetProcAddress("glSampleCoverage");
	glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)plGetProcAddress("glCompressedTexImage3D");
	glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)plGetProcAddress("glCompressedTexImage2D");
	glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)plGetProcAddress("glCompressedTexImage1D");
	glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)plGetProcAddress("glCompressedTexSubImage3D");
	glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)plGetProcAddress("glCompressedTexSubImage2D");
	glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)plGetProcAddress("glCompressedTexSubImage1D");
	glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)plGetProcAddress("glGetCompressedTexImage");
}

void LoadGL14Extensions()
{
	glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)plGetProcAddress("glBlendFuncSeparate");
	glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)plGetProcAddress("glMultiDrawArrays");
	glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)plGetProcAddress("glMultiDrawElements");
	glPointParameterf = (PFNGLPOINTPARAMETERFPROC)plGetProcAddress("glPointParameterf");
	glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)plGetProcAddress("glPointParameterfv");
	glPointParameteri = (PFNGLPOINTPARAMETERIPROC)plGetProcAddress("glPointParameteri");
	glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC)plGetProcAddress("glPointParameteriv");
	glBlendColor = (PFNGLBLENDCOLORPROC)plGetProcAddress("glBlendColor");
	glBlendEquation = (PFNGLBLENDEQUATIONPROC)plGetProcAddress("glBlendEquation");
}

void LoadGL15Extensions()
{
	glGenQueries = (PFNGLGENQUERIESPROC)plGetProcAddress("glGenQueries");
	glDeleteQueries = (PFNGLDELETEQUERIESPROC)plGetProcAddress("glDeleteQueries");
	glIsQuery = (PFNGLISQUERYPROC)plGetProcAddress("glIsQuery");
	glBeginQuery = (PFNGLBEGINQUERYPROC)plGetProcAddress("glBeginQuery");
	glEndQuery = (PFNGLENDQUERYPROC)plGetProcAddress("glEndQuery");
	glGetQueryiv = (PFNGLGETQUERYIVPROC)plGetProcAddress("glGetQueryiv");
	glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)plGetProcAddress("glGetQueryObjectiv");
	glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)plGetProcAddress("glGetQueryObjectuiv");
	glBindBuffer = (PFNGLBINDBUFFERPROC)plGetProcAddress("glBindBuffer");
	glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)plGetProcAddress("glDeleteBuffers");
	glGenBuffers = (PFNGLGENBUFFERSPROC)plGetProcAddress("glGenBuffers");
	glIsBuffer = (PFNGLISBUFFERPROC)plGetProcAddress("glIsBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)plGetProcAddress("glBufferData");
	glBufferSubData = (PFNGLBUFFERSUBDATAPROC)plGetProcAddress("glBufferSubData");
	glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)plGetProcAddress("glGetBufferSubData");
	glMapBuffer = (PFNGLMAPBUFFERPROC)plGetProcAddress("glMapBuffer");
	glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)plGetProcAddress("glUnmapBuffer");
	glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)plGetProcAddress("glGetBufferParameteriv");
	glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)plGetProcAddress("glGetBufferPointerv");
}

void LoadGL20Extensions()
{
	glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)plGetProcAddress("glBlendEquationSeparate");
	glDrawBuffers = (PFNGLDRAWBUFFERSPROC)plGetProcAddress("glDrawBuffers");
	glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)plGetProcAddress("glStencilOpSeparate");
	glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)plGetProcAddress("glStencilFuncSeparate");
	glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)plGetProcAddress("glStencilMaskSeparate");
	glAttachShader = (PFNGLATTACHSHADERPROC)plGetProcAddress("glAttachShader");
	glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)plGetProcAddress("glBindAttribLocation");
	glCompileShader = (PFNGLCOMPILESHADERPROC)plGetProcAddress("glCompileShader");
	glCreateProgram = (PFNGLCREATEPROGRAMPROC)plGetProcAddress("glCreateProgram");
	glCreateShader = (PFNGLCREATESHADERPROC)plGetProcAddress("glCreateShader");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)plGetProcAddress("glDeleteProgram");
	glDeleteShader = (PFNGLDELETESHADERPROC)plGetProcAddress("glDeleteShader");
	glDetachShader = (PFNGLDETACHSHADERPROC)plGetProcAddress("glDetachShader");
	glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)plGetProcAddress("glDisableVertexAttribArray");
	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)plGetProcAddress("glEnableVertexAttribArray");
	glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)plGetProcAddress("glGetActiveAttrib");
	glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)plGetProcAddress("glGetActiveUniform");
	glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)plGetProcAddress("glGetAttachedShaders");
	glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)plGetProcAddress("glGetAttribLocation");
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)plGetProcAddress("glGetProgramiv");
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)plGetProcAddress("glGetProgramInfoLog");
	glGetShaderiv = (PFNGLGETSHADERIVPROC)plGetProcAddress("glGetShaderiv");
	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)plGetProcAddress("glGetShaderInfoLog");
	glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)plGetProcAddress("glGetShaderSource");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)plGetProcAddress("glGetUniformLocation");
	glGetUniformfv = (PFNGLGETUNIFORMFVPROC)plGetProcAddress("glGetUniformfv");
	glGetUniformiv = (PFNGLGETUNIFORMIVPROC)plGetProcAddress("glGetUniformiv");
	glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)plGetProcAddress("glGetVertexAttribdv");
	glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)plGetProcAddress("glGetVertexAttribfv");
	glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)plGetProcAddress("glGetVertexAttribiv");
	glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)plGetProcAddress("glGetVertexAttribPointerv");
	glIsProgram = (PFNGLISPROGRAMPROC)plGetProcAddress("glIsProgram");
	glIsShader = (PFNGLISSHADERPROC)plGetProcAddress("glIsShader");
	glLinkProgram = (PFNGLLINKPROGRAMPROC)plGetProcAddress("glLinkProgram");
	glShaderSource = (PFNGLSHADERSOURCEPROC)plGetProcAddress("glShaderSource");
	glUseProgram = (PFNGLUSEPROGRAMPROC)plGetProcAddress("glUseProgram");
	glUniform1f = (PFNGLUNIFORM1FPROC)plGetProcAddress("glUniform1f");
	glUniform2f = (PFNGLUNIFORM2FPROC)plGetProcAddress("glUniform2f");
	glUniform3f = (PFNGLUNIFORM3FPROC)plGetProcAddress("glUniform3f");
	glUniform4f = (PFNGLUNIFORM4FPROC)plGetProcAddress("glUniform4f");
	glUniform1i = (PFNGLUNIFORM1IPROC)plGetProcAddress("glUniform1i");
	glUniform2i = (PFNGLUNIFORM2IPROC)plGetProcAddress("glUniform2i");
	glUniform3i = (PFNGLUNIFORM3IPROC)plGetProcAddress("glUniform3i");
	glUniform4i = (PFNGLUNIFORM4IPROC)plGetProcAddress("glUniform4i");
	glUniform1fv = (PFNGLUNIFORM1FVPROC)plGetProcAddress("glUniform1fv");
	glUniform2fv = (PFNGLUNIFORM2FVPROC)plGetProcAddress("glUniform2fv");
	glUniform3fv = (PFNGLUNIFORM3FVPROC)plGetProcAddress("glUniform3fv");
	glUniform4fv = (PFNGLUNIFORM4FVPROC)plGetProcAddress("glUniform4fv");
	glUniform1iv = (PFNGLUNIFORM1IVPROC)plGetProcAddress("glUniform1iv");
	glUniform2iv = (PFNGLUNIFORM2IVPROC)plGetProcAddress("glUniform2iv");
	glUniform3iv = (PFNGLUNIFORM3IVPROC)plGetProcAddress("glUniform3iv");
	glUniform4iv = (PFNGLUNIFORM4IVPROC)plGetProcAddress("glUniform4iv");
	glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)plGetProcAddress("glUniformMatrix2fv");
	glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)plGetProcAddress("glUniformMatrix3fv");
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)plGetProcAddress("glUniformMatrix4fv");
	glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)plGetProcAddress("glValidateProgram");
	glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)plGetProcAddress("glVertexAttrib1d");
	glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)plGetProcAddress("glVertexAttrib1dv");
	glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)plGetProcAddress("glVertexAttrib1f");
	glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)plGetProcAddress("glVertexAttrib1fv");
	glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)plGetProcAddress("glVertexAttrib1s");
	glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)plGetProcAddress("glVertexAttrib1sv");
	glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)plGetProcAddress("glVertexAttrib2d");
	glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)plGetProcAddress("glVertexAttrib2dv");
	glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)plGetProcAddress("glVertexAttrib2f");
	glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)plGetProcAddress("glVertexAttrib2fv");
	glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)plGetProcAddress("glVertexAttrib2s");
	glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)plGetProcAddress("glVertexAttrib2sv");
	glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)plGetProcAddress("glVertexAttrib3d");
	glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)plGetProcAddress("glVertexAttrib3dv");
	glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)plGetProcAddress("glVertexAttrib3f");
	glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)plGetProcAddress("glVertexAttrib3fv");
	glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)plGetProcAddress("glVertexAttrib3s");
	glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)plGetProcAddress("glVertexAttrib3sv");
	glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)plGetProcAddress("glVertexAttrib4Nbv");
	glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)plGetProcAddress("glVertexAttrib4Niv");
	glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)plGetProcAddress("glVertexAttrib4Nsv");
	glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)plGetProcAddress("glVertexAttrib4Nub");
	glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)plGetProcAddress("glVertexAttrib4Nubv");
	glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)plGetProcAddress("glVertexAttrib4Nuiv");
	glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)plGetProcAddress("glVertexAttrib4Nusv");
	glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)plGetProcAddress("glVertexAttrib4bv");
	glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)plGetProcAddress("glVertexAttrib4d");
	glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)plGetProcAddress("glVertexAttrib4dv");
	glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)plGetProcAddress("glVertexAttrib4f");
	glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)plGetProcAddress("glVertexAttrib4fv");
	glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)plGetProcAddress("glVertexAttrib4iv");
	glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)plGetProcAddress("glVertexAttrib4s");
	glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)plGetProcAddress("glVertexAttrib4sv");
	glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)plGetProcAddress("glVertexAttrib4ubv");
	glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)plGetProcAddress("glVertexAttrib4uiv");
	glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)plGetProcAddress("glVertexAttrib4usv");
	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)plGetProcAddress("glVertexAttribPointer");
}

void LoadGL21Extensions()
{
	glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)plGetProcAddress("glUniformMatrix2x3fv");
	glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)plGetProcAddress("glUniformMatrix3x2fv");
	glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)plGetProcAddress("glUniformMatrix2x4fv");
	glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)plGetProcAddress("glUniformMatrix4x2fv");
	glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)plGetProcAddress("glUniformMatrix3x4fv");
	glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)plGetProcAddress("glUniformMatrix4x3fv");
}

void LoadGL30Extensions()
{
	glColorMaski = (PFNGLCOLORMASKIPROC)plGetProcAddress("glColorMaski");
	glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)plGetProcAddress("glGetBooleani_v");
	glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)plGetProcAddress("glGetIntegeri_v");
	glEnablei = (PFNGLENABLEIPROC)plGetProcAddress("glEnablei");
	glDisablei = (PFNGLDISABLEIPROC)plGetProcAddress("glDisablei");
	glIsEnabledi = (PFNGLISENABLEDIPROC)plGetProcAddress("glIsEnabledi");
	glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)plGetProcAddress("glBeginTransformFeedback");
	glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)plGetProcAddress("glEndTransformFeedback");
	glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)plGetProcAddress("glBindBufferRange");
	glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)plGetProcAddress("glBindBufferBase");
	glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)plGetProcAddress("glTransformFeedbackVaryings");
	glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)plGetProcAddress("glGetTransformFeedbackVarying");
	glClampColor = (PFNGLCLAMPCOLORPROC)plGetProcAddress("glClampColor");
	glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)plGetProcAddress("glBeginConditionalRender");
	glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)plGetProcAddress("glEndConditionalRender");
	glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)plGetProcAddress("glVertexAttribIPointer");
	glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)plGetProcAddress("glGetVertexAttribIiv");
	glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)plGetProcAddress("glGetVertexAttribIuiv");
	glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)plGetProcAddress("glVertexAttribI1i");
	glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)plGetProcAddress("glVertexAttribI2i");
	glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)plGetProcAddress("glVertexAttribI3i");
	glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)plGetProcAddress("glVertexAttribI4i");
	glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)plGetProcAddress("glVertexAttribI1ui");
	glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)plGetProcAddress("glVertexAttribI2ui");
	glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)plGetProcAddress("glVertexAttribI3ui");
	glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)plGetProcAddress("glVertexAttribI4ui");
	glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)plGetProcAddress("glVertexAttribI1iv");
	glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)plGetProcAddress("glVertexAttribI2iv");
	glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)plGetProcAddress("glVertexAttribI3iv");
	glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)plGetProcAddress("glVertexAttribI4iv");
	glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)plGetProcAddress("glVertexAttribI1uiv");
	glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)plGetProcAddress("glVertexAttribI2uiv");
	glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)plGetProcAddress("glVertexAttribI3uiv");
	glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)plGetProcAddress("glVertexAttribI4uiv");
	glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)plGetProcAddress("glVertexAttribI4bv");
	glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)plGetProcAddress("glVertexAttribI4sv");
	glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)plGetProcAddress("glVertexAttribI4ubv");
	glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)plGetProcAddress("glVertexAttribI4usv");
	glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)plGetProcAddress("glGetUniformuiv");
	glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)plGetProcAddress("glBindFragDataLocation");
	glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)plGetProcAddress("glGetFragDataLocation");
	glUniform1ui = (PFNGLUNIFORM1UIPROC)plGetProcAddress("glUniform1ui");
	glUniform2ui = (PFNGLUNIFORM2UIPROC)plGetProcAddress("glUniform2ui");
	glUniform3ui = (PFNGLUNIFORM3UIPROC)plGetProcAddress("glUniform3ui");
	glUniform4ui = (PFNGLUNIFORM4UIPROC)plGetProcAddress("glUniform4ui");
	glUniform1uiv = (PFNGLUNIFORM1UIVPROC)plGetProcAddress("glUniform1uiv");
	glUniform2uiv = (PFNGLUNIFORM2UIVPROC)plGetProcAddress("glUniform2uiv");
	glUniform3uiv = (PFNGLUNIFORM3UIVPROC)plGetProcAddress("glUniform3uiv");
	glUniform4uiv = (PFNGLUNIFORM4UIVPROC)plGetProcAddress("glUniform4uiv");
	glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)plGetProcAddress("glTexParameterIiv");
	glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)plGetProcAddress("glTexParameterIuiv");
	glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)plGetProcAddress("glGetTexParameterIiv");
	glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)plGetProcAddress("glGetTexParameterIuiv");
	glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)plGetProcAddress("glClearBufferiv");
	glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)plGetProcAddress("glClearBufferuiv");
	glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)plGetProcAddress("glClearBufferfv");
	glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)plGetProcAddress("glClearBufferfi");
	glGetStringi = (PFNGLGETSTRINGIPROC)plGetProcAddress("glGetStringi");
	glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)plGetProcAddress("glIsRenderbuffer");
	glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)plGetProcAddress("glBindRenderbuffer");
	glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)plGetProcAddress("glDeleteRenderbuffers");
	glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)plGetProcAddress("glGenRenderbuffers");
	glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)plGetProcAddress("glRenderbufferStorage");
	glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)plGetProcAddress("glGetRenderbufferParameteriv");
	glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)plGetProcAddress("glIsFramebuffer");
	glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)plGetProcAddress("glBindFramebuffer");
	glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)plGetProcAddress("glDeleteFramebuffers");
	glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)plGetProcAddress("glGenFramebuffers");
	glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)plGetProcAddress("glCheckFramebufferStatus");
	glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)plGetProcAddress("glFramebufferTexture1D");
	glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)plGetProcAddress("glFramebufferTexture2D");
	glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)plGetProcAddress("glFramebufferTexture3D");
	glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)plGetProcAddress("glFramebufferRenderbuffer");
	glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)plGetProcAddress("glGetFramebufferAttachmentParameteriv");
	glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)plGetProcAddress("glGenerateMipmap");
	glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)plGetProcAddress("glBlitFramebuffer");
	glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)plGetProcAddress("glRenderbufferStorageMultisample");
	glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)plGetProcAddress("glFramebufferTextureLayer");
	glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)plGetProcAddress("glMapBufferRange");
	glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)plGetProcAddress("glFlushMappedBufferRange");
	glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)plGetProcAddress("glBindVertexArray");
	glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)plGetProcAddress("glDeleteVertexArrays");
	glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)plGetProcAddress("glGenVertexArrays");
	glIsVertexArray = (PFNGLISVERTEXARRAYPROC)plGetProcAddress("glIsVertexArray");
}

void LoadGL31Extensions()
{
	glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)plGetProcAddress("glDrawArraysInstanced");
	glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)plGetProcAddress("glDrawElementsInstanced");
	glTexBuffer = (PFNGLTEXBUFFERPROC)plGetProcAddress("glTexBuffer");
	glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)plGetProcAddress("glPrimitiveRestartIndex");
	glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)plGetProcAddress("glCopyBufferSubData");
	glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)plGetProcAddress("glGetUniformIndices");
	glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)plGetProcAddress("glGetActiveUniformsiv");
	glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)plGetProcAddress("glGetActiveUniformName");
	glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)plGetProcAddress("glGetUniformBlockIndex");
	glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)plGetProcAddress("glGetActiveUniformBlockiv");
	glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)plGetProcAddress("glGetActiveUniformBlockName");
	glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)plGetProcAddress("glUniformBlockBinding");
	glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)plGetProcAddress("glBindBufferRange");
	glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)plGetProcAddress("glBindBufferBase");
	glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)plGetProcAddress("glGetIntegeri_v");
}

bool LoadGLExtensions()
{
	plGetProcAddress = (PFNPROCADDR)wglGetProcAddress;

	GLVERSION ver;
	if (!GetGLVersion(&ver))
		return false;

	if (ver.minor >= 1 && ver.major >= 2)
		LoadGL12Extensions();

	if (ver.minor >= 1 && ver.major >= 3)
		LoadGL13Extensions();

	if (ver.minor >= 1 && ver.major >= 4)
		LoadGL14Extensions();

	if (ver.minor >= 1 && ver.major >= 5)
		LoadGL15Extensions();

	if (ver.minor >= 2 && ver.major >= 0)
		LoadGL20Extensions();

	if (ver.minor >= 2 && ver.major >= 1)
		LoadGL21Extensions();

	if (ver.minor >= 3 && ver.major >= 0)
		LoadGL30Extensions();

	if (ver.minor >= 3 && ver.major >= 1)
		LoadGL31Extensions();

	return true;
}