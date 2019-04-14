#include "stdafx.h"
#include "Single_List.h"

void ListOps(void){
	Single_List<int> num(10);
	for(int i =0 ;i <10 ;i ++){
		num.insert_node(i,num.get_length());
	}
	num.insert_node(80,num.get_length());
	for(auto it = num.begin(); it!=num.end() ; ++it){
		std::cout<<*it<<endl;
	}

	num.reverse_list();
	//num.print_list();

	Single_List<int> num2(num);

	num2.print_list();

	Single_List<int> num3 = num2;
	num3.print_list();
}
