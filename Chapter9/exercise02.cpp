#include "../std_lib_facilities.h"
using namespace std;

class Name_pairs{
public:
    void read_names();
    void read_ages();
    void print()const;
    void sort();
    const vector<string>& get_name() const {return name;}
    const vector<double>& get_age() const {return age;}
private:
    vector<string> name;
    vector<double> age;    
};

void Name_pairs::read_names(){
    cout << "Enter names, enter 'NoName' to finish" << endl;
    string s;
    while(cin >> s && s != "NoName"){
        for(int i=0; i<name.size(); i++){
            if(name[i] == s) error("Name exists already: ", s);
        }
        name.push_back(s);
    }
}

void Name_pairs::read_ages(){
    for(int i=0; i<name.size(); i++){
        cout << "Enter age for: " << name[i] << endl;
        double a;
        cin >> a;
        age.push_back(a);
    }
}

void Name_pairs::print() const{
    for(int i=0; i<name.size(); i++){
        cout << "Name: " << name[i] << " aged: " << age[i] << endl;
    }
}

void Name_pairs::sort() {
    if(name.size() != age.size()) error("sort(): name and age must be the same size");

    vector<string> nameOriginal = name;
    vector<double> ageOriginal = age;
    std::sort(name.begin(), name.end());
    for(int i=0; i<name.size(); i++){
        for(int j=0; j<nameOriginal.size(); j++){
            if(name[i] == nameOriginal[j]){
                age[i] = ageOriginal[j];
            }
        }
    }

}

bool operator==(const Name_pairs& a, const Name_pairs& b){
    if(a.get_name().size() != b.get_name().size() || a.get_age().size() != b.get_age().size()){
        return false;
    }
    for(int i=0; i<a.get_name().size(); i++){
        if(a.get_name()[i] != b.get_name()[i]){
            return false;
        }
    }
    for(int i=0; i<a.get_age().size(); i++){
        if(a.get_age()[i] != b.get_age()[i]){
            return false;
        }
    }
    return true;
}

bool operator!=(const Name_pairs& a, const Name_pairs&b){
    return !(a==b);
}

ostream& operator<<(ostream& os, const Name_pairs& np){
    if(np.get_name().size() != np.get_age().size())
        error("<<: name and age must be the same size");
    for(int i=0; i<np.get_name().size(); i++){
        os << '(' << np.get_name()[i] << ',' << np.get_age()[i] << ')' << endl;
    }
    return os;
}

int main(){
    Name_pairs np1;
    np1.read_names();
    np1.read_ages();

    np1.print();
    np1.sort();

    Name_pairs np2;
    np2.read_names();
    np2.read_ages();
    if(np1 == np2){
        cout << "equal" << endl;
    }
    if(np1 != np2){
        cout << "Not equal" << endl;
    }
    cout << np1;
    cout << np2;
}