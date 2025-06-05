#include<iostream>
#include<list>

//auto类型不能作为左值，所以应该换成auto&
auto MIN(std::list<auto>& lst){
    auto iter = lst.begin(),iter_of_min = iter;
    for(iter++;iter != lst.end();iter++){
        if(*iter_of_min>*iter){
            iter_of_min = iter;
        }
        return *iter_of_min;
    }
}

int main(){
    std::list<int>Li{1,2,3};
    std::list<double>Ld={-4,-10,-5};
    MIN(Ld) = MIN(Li);
    std::cout<<MIN(Ld)<<std::endl;
}