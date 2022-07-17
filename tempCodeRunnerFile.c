struct data{
	char arr[500];
	int sz;
};

struct output{
    char ans[500];
};

program PALI_PROG{
    version PALI_VERS{
        output PALINDROM(data)=1;
    }=3;
}=0x3333333;