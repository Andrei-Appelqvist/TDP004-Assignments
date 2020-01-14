#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <iomanip>
#include <map>
#include <algorithm>
#include "ordlista.h"

std::vector<std::string> read_file(std::string filename){
  std::ifstream file;
  file.open (filename);
  if (!file.is_open()){
    std::cerr << "Error: File not found." << '\n';
  }
  std::string word;
  std::vector<std::string> vect;
  while (file >> word)
  {
      vect.push_back(word);
  }
  return vect;
}

std::vector<std::string> word_check(std::vector<std::string> vect){
  std::vector<std::string> new_vect{};
  auto word_checker = [&](std::string it){
    bool valid{true};
    if(it.size() < 3){
      valid = false;
    }
    int index{1};
    for_each(it.begin(), it.end(),[&index, &it, &valid](char c){
    if(c == '-' && it[index] == '-'){
      valid = false;
    }
    else if(c == '\'' && it[index] == 's'
          && it[index+1] == '\''){
      valid = false;
    }
    else if(c != '-' && c != '\'' && !isalpha(c)){
      valid = false;
    }
  ++index;
});
  if(valid == true){
    new_vect.push_back(it);
  }
  };
  for_each(vect.begin(),vect.end(), word_checker);
   return new_vect;
}

std::string word_clean(std::string word){
  std::size_t first_found = word.find_first_not_of("\'\"(");
  word.erase(0, first_found);
  std::size_t last_found = word.find_last_not_of("!?;,:).\"\'");
  if (word.size()!= 0){
    word.erase(last_found+1, word.size());
  std::transform(word.begin(), word.end(), word.begin(), ::tolower);
  }
  return word;
}


std::vector<std::string> clean_vect(std::vector<std::string> vect){
  std::transform(vect.begin(), vect.end(), vect.begin(), [](std::string wd)-> std::string{return word_clean(wd);});
  vect = word_check(vect);
  return vect;
}

std::vector<std::string> make_unique(std::vector<std::string> vec){
  std::set<std::string> un_set(vec.begin(), vec.end());
  std::vector<std::string> unique_vect(un_set.begin(), un_set.end());
  return unique_vect;
}

std::map<std::string, int> unique_count(std::vector<std::string> vec,
                          std::vector<std::string> uni){
    std::map<std::string, int> final_map{};
    for_each(uni.begin(), uni.end(), [&](std::string s){
      final_map.insert(std::make_pair(s, count(vec.begin(), vec.end(), s)));
    });
    return final_map;
}


void print(std::map<std::string, int> map, int d){
  std::map<std::string, int>::iterator it = map.begin();

  int print_length{0};
  //Kommentar: Ni bör använda exempelvis std::max när ni nu försöker
  //hitta max elementet i er map.
  std::for_each(map.begin(), map.end(),[&](std::pair<std::string, int> element){
    std::string word = element.first;
    if(word.size() > print_length){
          print_length = word.size();
        }
  });

  if (d == 0){
    std::vector<std::pair<int, std::string>> ve;
    std::for_each(map.begin(), map.end(),[&](std::pair<std::string, int> element){
      ve.push_back(std::make_pair(element.second, element.first));
    });

    std::sort(ve.begin(), ve.end());
    std::reverse(ve.begin(), ve.end());
    for (int x{0}; x < ve.size(); ++x){
      std::cout << std::setw(print_length) << ve[x].second << ' '
                << ve[x].first << '\n';
    }
  }
  else if (d == 1){
    for (it = map.begin(); it != map.end(); it++){
      std::cout << std::setw(print_length) << std::left << it->first << " "
                << it->second << '\n';
    }
  }
}
void print_o(std::vector<std::string> vect, int length){
  std::string string_final{};
  auto string_add = [&](std::string s){
    if (string_final.size() == 0){
      string_final += s;
    }
    else if ((string_final.size() + 1 + s.size()) < length){
      string_final += " ";
      string_final += s;
    }
    else{
      std::cout << string_final << '\n';
      string_final = s;
    }
  };

  //Kommentar: Bra att ni använder for each
  std::for_each(vect.begin(), vect.end(), string_add);
  std::cout << string_final << '\n';
}


int main(int argc, char const *argv[]) {
  std::vector<std::string> args(argv, argv + argc);
  if(args.size() == 1){
    std::cerr << "Error: No arguments given." << '\n';
    std::cerr << "Usage: a.out FILE [-a] [-f] [-o N]" << '\n';
    return 0;
  }
  else if(args.size() == 2){
    std::cerr << "Error: Second argument missing or invalid." << '\n';
    std::cerr << "Usage: a.out FILE [-a] [-f] [-o N]" << '\n';
    return 0;
  }
  std::vector<std::string> vect{read_file(args[1])};
  vect = clean_vect(vect);
  if (args.size() == 4 && args[2] == "-o"){
    print_o(vect, stoi(args[3]));
  }
  else if(args.size() == 3 && args[2] == "-a"){
    print(unique_count(vect, make_unique(vect)), 1);
  }
  else if(args.size() == 3 && args[2] == "-f"){
    print(unique_count(vect, make_unique(vect)), 0);
  }
  return 0;
}
