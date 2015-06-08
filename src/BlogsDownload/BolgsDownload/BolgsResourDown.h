#pragma once

class BolgsResourDown
{
public:
	BolgsResourDown(void);
	~BolgsResourDown(void);
public:
	std::string getHtml(std::string url);
	int downloadResource(std::string srcurl,std::string dcesurl);

};

