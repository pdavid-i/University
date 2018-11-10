#include "Domain.h"
#include <sstream>
#include <vector>

std::istream& operator>> (std::istream& is, Question& q)
{
	std::string line;
	std::getline(is, line);
	std::stringstream aux;
	aux.str(line);
	std::vector<std::string> fields;
	while (std::getline(aux, line, '|'))
	{
		fields.push_back(line);
	}
	if (fields.size() == 4)
	{
		q.id = std::stoi(fields[0]);
		q.text = fields[1];
		q.answer = fields[2];
		q.score = std::stoi(fields[3]);
	}
	return is;
}

std::istream& operator>> (std::istream& is, Player& p)
{
	std::string line;
	std::getline(is, line);
	std::stringstream aux;
	aux.str(line);
	std::vector<std::string> fields;
	while (std::getline(aux, line, '|'))
	{
		fields.push_back(line);
	}
	if (fields.size() == 2)
	{
		p.name = fields[0];
		p.score = std::stoi(fields[1]);
	}
	return is;
}
