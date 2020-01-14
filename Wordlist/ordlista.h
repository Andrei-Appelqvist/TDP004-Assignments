#ifndef ORDLISTA_H
#define ORDLISTA_H
std::vector<std::string> read_file(std::string);
std::vector<std::string> clean_vect(std::vector<std::string>);
std::string word_clean(std::string word);
std::vector<std::string> word_check(std::vector<std::string> vect);
std::vector<std::string> make_unique(std::vector<std::string> vec);
std::map<std::string, int> unique_count(std::vector<std::string> vec, std::vector<std::string> uni);
void print(std::map<std::string, int>, int);
void print_o(std::vector<std::string>);
#endif//ORDLISTA_H
