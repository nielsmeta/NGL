#pragma once

class Shader
{
private:
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;

	const char* vertexShaderName;
	const char* fragmentShaderName;

public:

	void InitShader(const char* vertexFilePath, const char* fragmentFilePath);

	void CheckShader(unsigned int shader);

	void CheckProgram();

	void Use();

	int GetUniformIdByName(const char* name);

	void SetUniform4f(int locationId, float a, float b, float c, float d);

	void SetBool(const char* name, bool s);

	void SetFloat(const char* name, float v);

	void SetDouble(const char* name, double v);

	void SetInt(const char* name, int v);

	void SetUniform4f(const char* name, float a, float b, float c, float d);
};