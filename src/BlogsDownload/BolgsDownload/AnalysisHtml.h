#pragma once

class AnalysisHtml
{
public:
	virtual ~AnalysisHtml(){};
	//������ҳ��Ϣ
	//mainUrl Ҫ��������ҳ
	virtual int AnalysisHtmlMain(std::string mainUrl) =0;
	//���ز�����ҳ����Ϣ
	virtual BolgMainInfo& getHtmlMainInfor() =0;
	//���ز��͵Ĳ����б�
	virtual std::vector<std::string>& getHtmlListVector() =0;
	//��������
	virtual int AnalysisListHtml(std::string bolgurl) =0;
	//���ز�����Ϣ
	virtual BolgListItem& getHtmlListHtml()=0;
};