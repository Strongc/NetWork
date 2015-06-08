#pragma once
class CSDNAnalysisHtml:public AnalysisHtml
{
public:
	CSDNAnalysisHtml(void);
	~CSDNAnalysisHtml(void);
public:
	int AnalysisHtmlMain(std::string mainUrl);
	BolgMainInfo& getHtmlMainInfor();
	std::vector<std::string>& getHtmlListVector();
	int AnalysisListHtml(std::string bolgurl);
	BolgListItem& getHtmlListHtml();
};

