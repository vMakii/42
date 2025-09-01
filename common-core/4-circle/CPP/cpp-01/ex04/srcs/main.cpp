/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:00:00 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/01 12:24:02 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	printUsage(const char *programName)
{
	std::cout << "Usage: " << programName << " <filename> <string_to_replace> <replacement_string>" << std::endl;
}

int	openStreams(std::ifstream *ifs, std::ofstream *ofs, const std::string &infile, const std::string &outfile)
{
	ifs->open(infile.c_str());
	if (!ifs->is_open())
	{
		std::cerr << "Error: cannot open file " << infile << std::endl;
		return -1;
	}
	
	ofs->open(outfile.c_str());
	if (!ofs->is_open())
	{
		std::cerr << "Error: cannot create file " << outfile << std::endl;
		ifs->close();
		return -1;
	}
	
	return 0;
}

std::string	replaceAll(const std::string &str, const std::string &target, const std::string &replacement)
{
	if (target.empty())
		return str;
	
	std::string result = str;
	size_t pos = 0;
	
	while ((pos = result.find(target, pos)) != std::string::npos)
	{
		result.erase(pos, target.length());
		result.insert(pos, replacement);
		pos += replacement.length();
	}
	
	return result;
}

int	processFile(std::ifstream *ifs, std::ofstream *ofs, const std::string &target, const std::string &replacement)
{
	std::string line;
	bool first = true;
	
	while (std::getline(*ifs, line))
	{
		if (!first)
			*ofs << std::endl;
		
		std::string processedLine = replaceAll(line, target, replacement);
		*ofs << processedLine;
		first = false;
	}
	
	return 0;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		printUsage(argv[0]);
		return 1;
	}
	
	std::string infile = argv[1];
	std::string outfile = infile + ".replace";
	std::string target = argv[2];
	std::string replacement = argv[3];
	
	std::ifstream ifs;
	std::ofstream ofs;
	
	if (openStreams(&ifs, &ofs, infile, outfile) == -1)
		return 1;
	
	if (processFile(&ifs, &ofs, target, replacement) == -1)
	{
		ifs.close();
		ofs.close();
		return 1;
	}
	
	ifs.close();
	ofs.close();
	
	std::cout << "File processed successfully. Output written to " << outfile << std::endl;
	
	return 0;
}
