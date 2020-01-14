
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <set>

using namespace std;

int main() {
  ifstream file;
  file.open ("example.txt");
  if (!file.is_open()){
    std::cout << "shit!" << '\n';
  }
  string word;
  string all;
  //tar in all text till sträng
  while (file >> word)
  {
      all += word;
      all += " ";
  }
  //gör till lowercase
  transform(all.begin(), all.end(), all.begin(), ::tolower);
  //rensar bort all tecken
  for(int i = 0; i < all.size(); ++i)
  {
      if (!((all[i] >= 'a' && all[i]<='z') || (all[i] >= 'A' && all[i]<='Z') || (all[i]=='-')))
      {
          all[i] = '\0';
      }
  }
  //lägger in i vector(splittar där \0 finns vilket ger massor av element som
  // har längden noll eller ett som inte innehåller bokstäver.)
  vector<string> results;
  boost::split(results, all, [](char c){return c== '\0';});

  //skapar ny vector där jag lägger in alla som är större än 2
  vector<string> clean;
  for(int i = 0; i < results.size(); ++i){
    if (results[i].size() > 2){
      clean.push_back(results[i]);
      //cout << results[i] << '|' << results[i].size() << '|' << results[i].length()<<'\n';
    }
  }

  int cnt{0};
  set<string> uq(clean.begin(), clean.end());
  vector<string> test (uq.begin(), uq.end());
  for(int i = 0; i < test.size(); ++i){
    int cnt = count(clean.begin(), clean.end(), test[i]);
    cout << test[i] << ' ' << cnt << '\n';
  }
  //får rätt antal ord men fler än i uppgift. Skituppgift!






  //sorterar vectorn så att alla likadana hamnar bredvid varandra
  //viktigt för att for loopen ska funka.
  /*
  sort(clean.begin(), clean.end());

  int vec_size = clean.size();

  string words;
  int wordCount = 1;
  words = clean[0];
  //Loopar genom vectorn, om det nya ordet = words count += 1
  //annars skriver ut ordet och hur många gånger det förekom.
  for(int i = 1; i<vec_size;++i){
    if(words!=clean[i]){
      cout << words << " appeared "<< wordCount << " times. "<< '\n';
      wordCount = 0;
      words=clean[i];
    }
    wordCount++;
  }
  cout << words << " appeared "<< wordCount << " times. "<< '\n';
*/
  return 0;
}

/*
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    ifstream file;
    file.open ("test.html");
    if (!file.is_open()){
      std::cout << "shit!" << '\n';
    }
    string word;
    string all;
    while (file >> word)
    {
        all += word;
        all += " ";
    }
  cout << all << '\n';
  all.erase(remove(all.begin(), all.end(), '<'), all.end());
  all.erase(remove(all.begin(), all.end(), '>'), all.end());
  cout << all << '\n';
  return 0;
}

int main() {
  std::string line;
  std::ifstream myfile("test.html");
  if (myfile.is_open()){
    while (getline (myfile, line)){
      std::cout << line << '\n';
    }
    myfile.close();
  }
  else{
    std::cout << "Unable to open file" << '\n';
  }
  return 0;
}
*/
