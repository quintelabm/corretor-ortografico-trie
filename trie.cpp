
#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
// Estrutura de um no da Trie
struct TrieNode{
 
    // Armazena endereco do caractere 
    TrieNode* Trie[256];
 
    // Verifica se o caractere e o ultimo 
    // da string ou nao
    bool isEnd;
 
    // Construtor 
    TrieNode(){
 
        for (int i = 0; i < 256; i++){
 
            Trie[i] = NULL;
        }
        isEnd = false;
    }
};
 
// Funcao para inserir string na Trie
void InsertTrie(TrieNode* root, string s){
 
    TrieNode* temp = root;
 
    // Caminha na string, s
    unsigned long i;
    for ( i = 0; i < s.length(); i++) {
 
        if (temp->Trie[s[i]] == NULL) {
 
            // Inicializa o no
            temp->Trie[s[i]] = new TrieNode();
        }
 
        // Atualiza temp
        temp = temp->Trie[s[i]];
    }
 
    // Marca o ultimo caractere da string
    // como verdadeiro
    temp->isEnd = true;
}
 
// Funcao que imprime sugestoes da string
void printSuggestions(TrieNode* root, string res){
    
    // Se o caractere atual e o ultimo da string
    if (root->isEnd == true) {
 
        cout << res << " ";
    }
 
    // Itera sobre todos os caracteres possiveis 
    // da string
    for (int i = 0; i < 256; i++) {
 
        // Se o caractere atual esta presente na Trie
        if (root->Trie[i] != NULL) {
 
            // Insere caractere atual na Trie
            res.push_back(i);
            printSuggestions(root->Trie[i], res);
            res.pop_back();
        }
    }
}
 
// Funcao que verifica se a string esta presente
// na Trie ou nao
bool checkPresent(TrieNode* root, string key)
{
    unsigned long i;
    // caminha na string
    for (i = 0; i < key.length(); i++) {
 
        // Se o caractere atual nao esta presente na Trie
        if (root->Trie[key[i]] == NULL) {

            // imprime sugestoes            
            printSuggestions(root, key.substr(0, i));

            return false;
        }
 
        // atualiza root
        root = root->Trie[key[i]];
    }
    if (root->isEnd == true) {
 
        return true;
    }    
    printSuggestions(root, key);
 
    return false;
}
 
// Funcao principal
int main()
{
     // Dado um array de strings
    const char* args[] = { "estrutura", "estruturas", "estruturas de dados", 
                            "dado", "dados" };
    vector<string> str(args,args+5);
 
    // e a chave que queremos verificar
    string key = "estutura";
 
    // Initializa a Trie
    TrieNode* root = new TrieNode();
 
    // Insere strings na Trie
    unsigned long i;
    for (i = 0; i < str.size(); i++) {
        InsertTrie(root, str[i]);
    }
    // Verifica se a chave esta presente na Trie
    if (checkPresent(root, key)) {
        cout << "YES";
    }
    return 0;
}