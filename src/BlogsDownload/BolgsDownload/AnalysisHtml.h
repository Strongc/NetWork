#pragma once

class AnalysisHtml
{
public:
	virtual ~AnalysisHtml(){};
	//解析主页信息
	//mainUrl 要解析的主页
	virtual int AnalysisHtmlMain(std::string mainUrl) =0;
	//返回博客主页的信息
	virtual BolgMainInfo& getHtmlMainInfor() =0;
	//返回博客的博文列表
	virtual std::vector<std::string>& getHtmlListVector() =0;
	//解析博文
	virtual int AnalysisListHtml(std::string bolgurl) =0;
	//返回博文信息
	virtual BolgListItem& getHtmlListHtml()=0;
};