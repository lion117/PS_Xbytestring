#include "StdAfx.h"
#include "Xbytestring.h"
#include <assert.h>

Xbytestring::Xbytestring(void)
{
	clear();			// initialize data
}

Xbytestring::Xbytestring( u_char *pchar , u_int nlenth )
{	
	clear();
	if (nlenth ==0 || pchar == NULL)
	{
		return;
	}
	Copy_deep(pchar , nlenth);
}

Xbytestring::Xbytestring( string pstring )
{

	clear();
	u_int nsize = pstring.size();
	if (nsize ==0)
	{
		return;
	}

	Copy_deep( (u_char *)pstring.c_str() , pstring.size());

}

Xbytestring::Xbytestring( const Xbytestring &obj_string )
{
	clear();
	this->list_datastring = obj_string.list_datastring;
}


u_char & Xbytestring::operator[]( u_int nindex )
{
	u_char pctemp = '\0';
	if (nindex <0 || nindex >= list_datastring.size())
	{
		// out of field
		assert(1!=1);	
		return pctemp;
	}
	return list_datastring.at(nindex);
}

Xbytestring Xbytestring::operator+( Xbytestring & obj_a  )
{
	Xbytestring temp_obj;
	temp_obj.append(*this);
	temp_obj.append(obj_a);
	return temp_obj;

}

Xbytestring::~Xbytestring(void)
{
	clear();
}

void Xbytestring::clear()
{
	list_datastring.clear();
}

void Xbytestring::c_str( u_char *pchar )
{
	u_int nsize = list_datastring.size();
	if (nsize == 0)
	{
		return;
	}
	memset(pchar , 0 , nsize);
	  
	for (u_int i =0; i< nsize; i++)
	{
		pchar[i] = list_datastring.at(i);
	}

}

u_int Xbytestring::size()
{
	return list_datastring.size();
}

u_char Xbytestring::at( u_int nindex )
{
	if (list_datastring.size() == 0 || nindex > list_datastring.size() -1)
	{
		// error occured
		assert(1!=1);
	}
	return list_datastring.at(nindex);

}

bool Xbytestring::empty()
{
	if (list_datastring.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Xbytestring::Copy_deep( u_char * pstr , u_int nlenth )
{
	if (nlenth ==0 || pstr == NULL)
	{
		return false;
	}
	
	// store data into vector 
	for (u_int i=0; i< nlenth; i++)
	{
		list_datastring.push_back(pstr[i]);
	}
	return true;
}

void Xbytestring::Set_data( u_char *pchar , u_int nlenth )
{
	clear();
	if (nlenth ==0 || pchar == NULL)
	{
		return;
	}
	Copy_deep(pchar , nlenth);
}

void Xbytestring::Set_data( string pstr )
{
	clear();
	if (pstr.empty())
	{
		return;
	}
	Copy_deep( (u_char* )pstr.c_str() , pstr.size());

}

void Xbytestring::setdata( u_char *pchar , u_int nlenth )
{
	this->Set_data(pchar,nlenth);
}

void Xbytestring::setdata( string pstr )
{
	this->Set_data(pstr);
}

void Xbytestring::setdata( Xbytestring pobj )
{
	if (pobj.empty())
	{
		return;
	}
	u_int nsize = pobj.size();
	this->clear();
	for(u_int i=0; i< nsize; i++)
	{
		this->list_datastring.push_back(pobj.at(i));
	}

}

std::string Xbytestring::tostring()
{
	string strtemp;
	strtemp.clear();
	if (list_datastring.empty())
	{
		return strtemp;
	}
	u_int nsize = list_datastring.size();
	u_char *pchartemp = new u_char[nsize +1];
	memset(pchartemp , 0 , nsize+1);
	for (u_int i =0; i< nsize; i++)
	{
		pchartemp[i] = list_datastring.at(i);
	}
	strtemp = (char *) pchartemp;		// data may lost in string as bit is 0
	return strtemp;
}

std::string Xbytestring::tosafestring()
{
	string temp;
	return temp;
}

void Xbytestring::append( u_char *pchar , u_int nlenth )
{
	if (nlenth < 1)
	{
		assert(1!=1);
		return;
	}
	for (u_int i=0; i< nlenth; i++)
	{
		list_datastring.push_back(pchar[i]);
	}

}

void Xbytestring::append( string pstring )
{
	int nsize = pstring.size();
	if (nsize ==0)
	{
		return;
	}
	for (int i= 0; i< nsize; i++)
	{
		list_datastring.push_back(pstring.at(i));
	}
}

void Xbytestring::append( u_char pchar )
{
	this->list_datastring.push_back(pchar);
}

void Xbytestring::append( Xbytestring pobj )
{	
	if (pobj.empty())
	{
		return;
	}

	u_int nsize = pobj.size();

	for (u_int i=0; i< nsize; i++)
	{
		list_datastring.push_back(pobj.at(i));
	}
}

void Xbytestring::erease( u_int nindex )
{
	u_int nsize = list_datastring.size();
	if ( nindex< 0 || nindex >= nsize)
	{
		return;
	}
	vector<u_char>::iterator itor;
	itor= list_datastring.begin() + nindex;
	list_datastring.erase(itor);

}
