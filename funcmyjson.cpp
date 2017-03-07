#include "json/json.h"
#include <fstream>i

/*
参数            类型	是否必需    描述
docinfos    array   Y	    表示多个入口文档信息
docid	        string	Y	表示文件或文件夹的id
doctype	        string	Y	表示入口文档的类型，
		    值“userdoc”对应用户文档；
		    值“groupdoc”对应群组文档； 
			值“customdoc”对应自定义组织文档；
		    值”sharedoc”对应共享文档; archivedoc”对应归档库;
typename    string  Y	    表示文档类型的显示名称
docname	    string  Y	    表示文档的显示名称
otag	    string  Y	    文件变化标识
size	    int64   Y	    -1表示为文件夹，>=0表示为文件




*/

using namespace std;
int ParseJsonFromFile(const char* filename)  
{  
  // 解析json用Json::Reader  
  Json::Reader reader;  
  // Json::Value是一种很重要的类型，可以代表任意类型。如int, string, object, array...  
  Json::Value root;         
  
  std::ifstream is;  
  is.open (filename, ios::binary );    
  int numFolder = 0;//文件夹数量
  int numDoc = 0;   //文件数量

  if (reader.parse(is, root))  
  {  
    // 得到"files"的数组个数  
    int file_size = root["docinfos"].size();  
    
    string docid,doctype,dtypename,docname,otag; 
    long long dsize; 
    // 遍历数组  
    for(int i = 0; i < file_size; ++i)  
    { 
     
    docid = root["docinfos"][i]["docid"].asString();//文件或文件夹的id
    doctype = root["docinfos"][i]["doctype"].asString();/*表示入口文档的类型，
    值“userdoc”对应用户文档；
    值“groupdoc”对应群组文档；
    值“customdoc”对应自定义组织文档；
    值”sharedoc”对应共享文档; 
    值"archivedoc”对应归档库;
    */
    
    dtypename = root["docinfos"][i]["typename"].asString();//文档类型的显示名称
    docname= root["docinfos"][i]["docname"].asString();//文档的显示名称
    otag= root["docinfos"][i]["otag"].asString();//文件变化标识
    dsize= root["docinfos"][i]["size"].asInt();//-1表示为文件夹，>=0表示为文件
    if ( dsize == -1 ) {//如果为文件夹
	numFolder = numFolder + 1;
	cout<<"名称:"<<docname<<";\t类型:文件夹;"<<"\t文档类型:"<<dtypename<<endl;
    }
    else{
    
	cout<<"名称:"<<docname<<";\t类型:文  件;"<<"\t文档类型:"<<dtypename<<endl;
	numDoc = numDoc + 1;
    }
    }
    cout<<endl<<endl<<"文件夹个数:"<<numFolder<<endl; 
    cout<<"文 件 个数:"<<numDoc<<endl; 
  }  
  is.close();  
  return 0;  
}  

