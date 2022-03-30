#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class Shader
{
public:
	Shader(const char* vertexShaderPath,const char* fragmentShaderPath);
	void useProgram();
	void setBool(const string& name, bool value) const;
	void setInt(const string& name, int value) const;
	void setFloat(const string& name, float value) const;
	void setDouble(const string& name, double value) const;

private:
	int m_shader_id;
};