from csvreader import CsvReader

if __name__ == "__main__":
    print("=" * 70)
    print("Test 1: Lecture de good.csv SANS header")
    print("=" * 70)
    with CsvReader('good.csv') as file:
        if file is None:
            print("❌ Erreur: Impossible de lire le fichier")
        else:
            data = file.getdata()
            header = file.getheader()
            print(f"Header: {header}")
            print(f"Nombre de lignes de données: {len(data)}")
            print("Premières 3 lignes:")
            for row in data[:3]:
                print(f"  {row}")
    
    print("\n" + "=" * 70)
    print("Test 2: Lecture de good.csv AVEC header=True")
    print("=" * 70)
    with CsvReader('good.csv', header=True) as file:
        if file is None:
            print("❌ Erreur: Impossible de lire le fichier")
        else:
            data = file.getdata()
            header = file.getheader()
            print(f"Header: {header}")
            print(f"Nombre de lignes de données: {len(data)}")
            print("Premières 3 lignes:")
            for row in data[:3]:
                print(f"  {row}")
    
    print("\n" + "=" * 70)
    print("Test 3: Lecture avec skip_top=2 et skip_bottom=3")
    print("=" * 70)
    with CsvReader('good.csv', header=True, skip_top=2, skip_bottom=3) as file:
        if file is None:
            print("❌ Erreur: Impossible de lire le fichier")
        else:
            data = file.getdata()
            header = file.getheader()
            print(f"Header: {header}")
            print(f"Nombre de lignes après skip: {len(data)}")
            print(f"Première ligne: {data[0]}")
            print(f"Dernière ligne: {data[-1]}")
    
    print("\n" + "=" * 70)
    print("Test 4: Lecture de bad.csv")
    print("=" * 70)
    with CsvReader('bad.csv') as bad_file:
        if bad_file is None:
            print("❌ Le fichier est corrompu")
        else:
            print("✅ Le fichier est valide")
            data = bad_file.getdata()
            print(f"Nombre de lignes: {len(data)}")
            print(f"Premières 3 lignes: {data[:3]}")
    
    print("\n" + "=" * 70)
    print("Test 5: Fichier inexistant")
    print("=" * 70)
    with CsvReader('nonexistent.csv') as file:
        if file is None:
            print("✅ Retourne bien None pour un fichier inexistant")
        else:
            print("❌ Devrait retourner None")
    
    print("\n" + "=" * 70)
    print("Test 6: Fichier avec séparateur personnalisé (;)")
    print("=" * 70)
    # Créer un fichier de test avec des points-virgules
    with open('test_semicolon.csv', 'w') as f:
        f.write("Nom;Age;Ville\n")
        f.write("Alice;30;Paris\n")
        f.write("Bob;25;Lyon\n")
        f.write("Charlie;35;Marseille\n")
    
    with CsvReader('test_semicolon.csv', sep=';', header=True) as file:
        if file is None:
            print("❌ Erreur: Impossible de lire le fichier")
        else:
            data = file.getdata()
            header = file.getheader()
            print(f"Header: {header}")
            print(f"Données:")
            for row in data:
                print(f"  {row}")
    
    print("\n" + "=" * 70)
    print("Test 7: Fichier corrompu (nombre de champs incohérent)")
    print("=" * 70)
    # Créer un fichier corrompu
    with open('test_corrupted.csv', 'w') as f:
        f.write("Name,Age,City\n")
        f.write("Alice,30,Paris\n")
        f.write("Bob,25\n")  # Ligne avec trop peu de champs
        f.write("Charlie,35,London,Extra\n")  # Ligne avec trop de champs
    
    with CsvReader('test_corrupted.csv') as file:
        if file is None:
            print("✅ Détecte correctement la corruption du fichier")
        else:
            print("❌ Devrait détecter que le fichier est corrompu")
    
    print("\n" + "=" * 70)
    print("Tous les tests sont terminés!")
    print("=" * 70)