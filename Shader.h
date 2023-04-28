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

	/// <summary>
	/// ���þ���
	/// </summary>
	/// <param name="name">��������</param>
	/// <param name="value">����ֵ</param>
	/// <param name="mCount">�������,Ĭ��1</param>
	/// <param name="needTranspose">�Ƿ���Ҫת��,Ĭ��false</param>
	void SetUniformMatrix4fv(const char* name, float* value, int mCount = 1,bool needTranspose = false);
};