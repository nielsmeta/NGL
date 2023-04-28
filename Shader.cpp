#include"Shader.h"

#include"Base/head.h"
#include"FileHelper.h"

using namespace std;

void Shader::InitShader(const char* vertexFilePath, const char* fragmentFilePath)
{
	vertexShaderName = vertexFilePath;
	fragmentShaderName = fragmentFilePath;
	string vSource = FileHelper::ReadFileTxt(vertexFilePath);
	const char* vertexShaderSource = vSource.c_str();
	string fSource = FileHelper::ReadFileTxt(fragmentFilePath);
	const char* fragmentShaderSource = fSource.c_str();

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	CheckShader(vertexShader);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	CheckShader(fragmentShader);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	CheckProgram();
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::CheckShader(unsigned int shader)
{
	int  success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "Shader Compile ERROR::" << shader << "\n" << infoLog << std::endl;
	}
}

void Shader::CheckProgram()
{
	int  success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ShadeProgram Link ERROR::" << shaderProgram << "\n" << infoLog << std::endl;
	}
}

void Shader::Use()
{
	if (shaderProgram != 0)
	{
		glUseProgram(shaderProgram);
	}
}

int Shader::GetUniformIdByName(const char* name)
{
	return glGetUniformLocation(shaderProgram, name);
}

void Shader::SetUniform4f(int locationId, float a, float b, float c, float d)
{
	glUniform4f(locationId, a, b, c, d);
}

void Shader::SetBool(const char* name, bool s)
{
	glUniform1i(GetUniformIdByName(name), s == 1 ? 1 : 0);
}

void Shader::SetFloat(const char* name, float v)
{
	glUniform1f(GetUniformIdByName(name), v);
}

void Shader::SetDouble(const char* name, double v)
{
	glUniform1d(GetUniformIdByName(name), v);
}

void Shader::SetInt(const char* name, int v)
{
	glUniform1i(GetUniformIdByName(name), v);
}

void Shader::SetUniform4f(const char* name, float a, float b, float c, float d)
{
	SetUniform4f(GetUniformIdByName(name), a, b, c, d);
}

void Shader::SetUniformMatrix4fv(const char* name, float* value, int mCount, bool needTranspose)
{
	glUniformMatrix4fv(GetUniformIdByName(name), mCount, needTranspose, value);
}
