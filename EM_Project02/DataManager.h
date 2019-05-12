#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>

//�w�q���޸��class
class DataManager
{
private:
	//�x�s��{�����
	std::vector<std::string> Equations;
	std::vector<std::vector<std::string>> postfix_equations;
	//�����V�qID�A�Ω󱱺�
	int EquationIndex;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();
	//Ū���V�q���
	bool LoadEquationData();
	//���o�V�q���
	std::vector<std::string> GetEquations();
	std::vector<std::vector<std::string>> GetPostEquations();
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);
};