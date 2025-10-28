import time

def ft_progress(lst):
    """A simple progress bar generator."""
    total = len(lst)
    start_time = time.time()
    
    for i, item in enumerate(lst):
        # Calculer le temps écoulé
        elapsed_time = time.time() - start_time
        
        # Calculer le pourcentage
        progress = (i + 1) / total
        percentage = int(progress * 100)
        
        # Calculer l'ETA
        if i > 0:
            avg_time_per_item = elapsed_time / (i + 1)
            remaining_items = total - (i + 1)
            eta = avg_time_per_item * remaining_items
        else:
            eta = 0
        
        # Créer la barre de progression (largeur de 20 caractères)
        bar_width = 20
        filled_width = int(progress * bar_width)
        bar = '=' * filled_width + '>' if filled_width < bar_width else '=' * bar_width
        bar = bar.ljust(bar_width)
        
        # Formater et afficher la ligne de progression
        GREEN = '\033[92m'
        RESET = '\033[0m'
        progress_line = f"\rETA: {eta:.2f}s [{percentage:3d}%][{GREEN + bar + RESET}] {i+1}/{total} | elapsed time {elapsed_time:.2f}s"
        print(progress_line, end='', flush=True)
        
        yield item
    
    # Nouvelle ligne à la fin
    print()

if __name__ == "__main__":
    # listy = range(100)
    # ret = 0
    # for elem in ft_progress(listy):
    #     ret += (elem + 3) % 5
    #     time.sleep(0.01)
    # print('...')
    # print(ret)
    listy = range(3333)
    ret = 0
    for elem in ft_progress(listy):
        ret += elem
        time.sleep(0.005)
    print()
    print(ret)