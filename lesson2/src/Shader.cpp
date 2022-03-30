#include "Shader.h"

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
{
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	std::string vertexCode;
	std::string fragmentCode;
	try
	{
		// ���ļ�
		vShaderFile.open(vertexShaderPath);
		fShaderFile.open(fragmentShaderPath);

		std::stringstream vShaderStream, fShaderStream;
		// ��ȡ�ļ��Ļ������ݵ���������
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		// �ر��ļ�������
		vShaderFile.close();
		fShaderFile.close();
		// ת����������string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	// 2. ������ɫ��
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	// ������ɫ��
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	// ��ӡ�����������еĻ���
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}


	// ��ɫ������
	m_shader_id = glCreateProgram();
	glAttachShader(m_shader_id, vertex);
	glAttachShader(m_shader_id, fragment);
	glLinkProgram(m_shader_id);
	// ��ӡ���Ӵ�������еĻ���
	glGetProgramiv(m_shader_id, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(m_shader_id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// ɾ����ɫ���������Ѿ����ӵ����ǵĳ������ˣ��Ѿ�������Ҫ��
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}
void Shader::useProgram()
{
	glUseProgram(m_shader_id);
}
void Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(m_shader_id, name.c_str()), (int)value);
}
void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(m_shader_id, name.c_str()), value);
}
void Shader::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(m_shader_id, name.c_str()), value);
}
void Shader::setDouble(const string& name, double value) const
{
	glUniform1d(glGetUniformLocation(m_shader_id,name.c_str()), value);
}