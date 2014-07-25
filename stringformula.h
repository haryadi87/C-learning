int shoutorwhisper(char *msgin, char *msgout, int indicator) {
	if(!msgin || !msgout)
		return -1;
	while (*msgin != '\0') {
		if (indicator == 1) {
			if ('a' <= *msgin && *msgin <= 'z')
				*msgout = *msgin + ('A' - 'a');
		}
		if (indicator == 2) {
			if ('A' <= *msgin && *msgin <= 'Z')
				*msgout = *msgin - ('A' - 'a');
		}
		msgin++;
		msgout++;
	}
	*msgout='\0';
	return 0;
}
int strlen(char *string){
	if(!string) return 0;
	int count = 0;
	while(string[count])
		count++;
	return count;
}
int concat(char * str1, char * str2, char * out ) {
	if(!str1 || !str2 || !out ) {
		return -1;
	}
	int i=0;
	int j=0;
	while(str1[i] !='\0') {
		out[i]  = str1[i];
		i++;
	}
	while(str2[j] != '\0') {
		out[i] = str2[j];
		i++;
		j++;
	}
	out[i] = '\0';
	return 0;
}
int copyString(char *str1, char *out) {
	if(!str1 || !out)
		return -1;
	while(*str1 !='\0') {
		*out++ = *str1++;
	}
	*out ='\0';
	return 0;
}
int toneItDown(char *str1, char *out){
	if(!str1 || !out)
		return -1;
	while(*str1) {
		if(*str1 == '!') {
			*out = '.';
			*out++;
			*str1++;
		}
		else {
			*out++ = *str1++;
		}
	}
	*out = '\0';
	return 0;
}
int reverse(char *str1, char *out){
	if(!str1 || !out) return -1;
	int i;
	int j;
	for(i = 0; str1[i] != '\0'; i++) {

	}
	for(i--;i>=0;i--){
		*out = str1[i];
		*out++;
	}
	/*i--;
	for(j=0;j<i;j++) {
		out[j] =str1[i-j];

	}*/
	*out='\0';
	return 0;
}
int copyStringN(char * str1, char * str2, int n) {
	if(!str1 || !str2) {
		return -1;
	}
	int i;
	if(n > strlen(str1)) {
		return -2;
	}
	for(i = 0; i < n ; i++) {
		*str2++ = *str1++;
	}
	*str2 = '\0';
	return 0;
}
int decode(char *str, char *msg) {
	if(!str || !msg)
		return -1;
	char * word = str;
	int i=0;
	while(*str) {
		if(*str=='\n') {
			while(word!=str) {
				*msg++ = *word++;
			}
			*msg++ =' ';
			word++;
		}
		else if(*str==' ') {
			word = str+1;
		}
		str++;
	}
	*msg ='\0';
	return 0;
}
int decodeFirst(char *str, char *msg) {
	if(!str || !msg)
		return -1;
	char * word = str;
	int i=0;
	while(*str) {
		if(*str==' ' && i==0){
			while(word!=str) {
				*msg++ = *word++;
			}
			*msg++=' ';
			word++;
			i++;
		}
		else if(i!=0 && *str==' ') {
			word= str+1;
			i++;
		}
		else if(*str=='\n') {
			word = str+1;
			i=0;
		}
		str++;
	}
	*msg ='\0';
	return 0;
}
int xvowelize(char *in, char *out){
	if(!in || !out)
		return -1;
	while(*in){
		if(*in=='a' || *in=='i' || *in=='u' || *in=='e' || *in=='o' || *in=='A' || *in=='I' || *in=='U' || *in=='E' || *in=='O' ) {
			*in++;
		}
		else {
			*out++ = *in++;
		}
	}
	*out = '\0';
	return 0;
}
int streq(char *str1, char *str2) {
	if(!str1 || !str2)
		return 0;
	int check=0;
	while(*str1) {
		if(*str1++ == *str2++) {
			check=1;
		}
		else {
			check=0;
		}
	}
	if(strlen(str2) > strlen(str1)){
		check = 0;
	}
	return check;
}
int prefix(char *pre, char *str) {
	if(!pre || !str)
		return 0;
	int i;
	for(i=0; pre[i];i++) {
		if(pre[i] != str[i]) {
			return 0;
		}
	}
	return 1;
}
int sufix(char *suf, char*str) {
	if(!suf||!str)
		return 0;
	int i;
	char buffer[128];
	reverse(str,buffer);
	for(i=0;suf[i];i++) {
		if(suf[i]!=buffer[i]) {
			return 0;
		}
	}
	return 1;
}
int strcmp(char *str1, char *str2){
	if(!str1||!str2)
		return 0;
	int check;
	while(*str1) {
		if(*str1>=*str2)
			check=0;
		else if(*str1<*str2)
			check=1;
		*str1++;
		*str2++;
	}
	if(strlen(str1) > strlen(str2)) {
		return 1;
	}
	return check;
}
int hasSubstring (char *str, char *substr){
	if(!str || !substr)
		return 0;
	int m=0; //beginning of current match in str
	int i=0; //position of current character in substr
	int check=0;
	int result =0;
	int t[20];
	while(str[i]!='\0') {
		if(substr[0] == str[i]) {
			for(m=0; m<strlen(substr);m++) {
				if(substr[m]== str[i+m]) {
					check++;
				}
				else {
					check=0;
				}
				if(check == strlen(substr)) {
					result =1;
				}
			}
		}
		i++;
	}
	return result;
	/*while(m+i <strlen(str)) {
		if (substr[i] = str[m+i]) {
			if (i = strlen(substr) - 1) {
				return 1;
			}
			i++;
		}
		else if(t[i] > -1) {
			i = t[i];
			m = m+i-t[i];
		}
		else {
			i=0;
			m++;
		}
	}
	return 0;*/
}
void quickSort(int v[], int left, int right) {
	int i, last;
	void swap(int v[], int i, int j);
	if(left >= right)
		return;
	swap(v,left,(left+right)/2);
	last = left;
	for(i = left + 1; i <=right; i++) {
		if(v[i]<v[left])
			swap(v,++last,i);
	}
	swap(v,left,last);
	quickSort(v,left,last-1);
	quickSort(v,last+1,right);
}
double atof(char s[]) {
	double val, power;
	int i,sign;
	for(i=0;isspace(s[i]);i++)
		;
	sign = (s[i]=='-') ? -1 : 1;
	if(s[i]=='+' || s[i] == '-')
		i++;
	for(val =0.0;isdigit(s[i]);i++)
		val = 10.0 * val +(s[i]-'0');
	if(s[i]=='.')
		i++;
	for(power=1.0;isdigit(s[i]);i++){
		val = 10.0 * val + (s[i]-'0');
		power*=10.0;
	}
	return sign *val/power;
}
