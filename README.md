This project implements a simple bilingual dictionary in C, using a doubly linked list to store pairs of words and their respective translations. It allows for adding, searching, removing, and translating words, with an example usage in the main program.

### Project Structure
- `dictionary.h`: Defines the structure and functions of the dictionary.
- `main.c`: Example usage of the dictionary.

### Functionalities

- **Dictionary Initialization**
  - `inicializa_disc()`: Creates and returns a pointer to an initial node in the dictionary.

- **Word Insertion**
  - `inserir_palavra()`: Inserts a new word and its translation at the end of the list.

- **Word Removal**
  - `remover_palavra()`: Finds and removes a word from the dictionary, adjusting the pointers of adjacent nodes.

- **Word Search**
  - `buscar_palavra()`: Returns the node corresponding to the specified word, if it exists in the dictionary.

- **Dictionary Printing**
  - `imprimir_dicionario()`: Displays all words and their translations in the dictionary.

- **Text Translation**
  - `imprimir_texto()`: Translates words from a text string using the dictionary. Words not found are displayed without translation.
