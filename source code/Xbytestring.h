///////////////////////////////////////////////////////////////
/*
File name 	:   Xbytestring.h
Author 		: 	LEO
Date 		:	2015-3-12
Email  		:	lion_117@126.com
Description:
All Rights Reserved 
*/
///////////////////////////////////////////////////////////////


#pragma once
#include <string>
#include <vector>
using namespace  std;
typedef unsigned char u_char;
typedef unsigned int  u_int;



class Xbytestring
{

private:				// to realize the copy constructor fuction 
	vector<u_char>		list_datastring;

public:
	Xbytestring(void);
	Xbytestring(u_char *pchar , u_int nlenth);
	Xbytestring(string pstring);
	Xbytestring(const Xbytestring &obj_string);
	u_char &  operator[](u_int nindex);
	Xbytestring operator+(Xbytestring & obj_a );

	~Xbytestring(void);
	
public:
	u_int	size();
	u_char	at( u_int nindex);
	bool	empty();
	void	clear();
	void	c_str( u_char  *pchar );
	string	tostring();
	string  tosafestring();
	void	setdata(u_char *pchar , u_int nlenth);
	void	setdata(string pstr);
	void	setdata(Xbytestring pobj);
	//**********abandon function interface ******//
	void	Set_data(u_char *pchar , u_int nlenth);
	void	Set_data(string pstr);
	//*******************************************//
	void	append(u_char *pchar , u_int nlenth);
	void	append(string pstring);
	void	append(u_char  pchar);
	void	append(Xbytestring pobj);

	void	erease(u_int nindex);



private:
	bool Copy_deep(u_char * pstr , u_int nlenth);
};
