/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:00:00 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/01 12:33:37 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/*
 * Affiche le message d'usage du programme
 * Explique la syntaxe correcte avec les paramètres attendus
 */
void	printUsage(const char *programName)
{
	std::cout << "Usage: " << programName << " <filename> <string_to_replace> <replacement_string>" << std::endl;
}

/*
 * Ouvre les flux d'entrée et de sortie pour les fichiers
 * Vérifie que l'ouverture s'est bien passée et gère les erreurs
 * Retourne 0 en cas de succès, -1 en cas d'erreur
 */
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

/*
 * Remplace toutes les occurrences d'une chaîne cible par une chaîne de remplacement
 * Gère le cas où la chaîne cible est vide (aucun remplacement)
 * Évite les boucles infinies en ajustant la position après chaque remplacement
 */
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

/*
 * Traite le fichier ligne par ligne en appliquant les remplacements
 * Lit chaque ligne, applique la fonction replaceAll, et écrit dans le fichier de sortie
 * Gère correctement les sauts de ligne pour préserver le formatage
 */
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

/*
 * Fonction principale du programme
 * - Vérifie le nombre d'arguments
 * - Initialise les variables avec les paramètres
 * - Coordonne l'ouverture des fichiers, le traitement et la fermeture
 * - Gère les codes de retour pour indiquer le succès ou l'échec
 */
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
