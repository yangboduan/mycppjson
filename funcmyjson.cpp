#include "json/json.h"
#include <fstream>
using namespace std;
int ParseJsonFromFile(const char* filename)  
{  
  // 解析json用Json::Reader  
  Json::Reader reader;  
  // Json::Value是一种很重要的类型，可以代表任意类型。如int, string, object, array...  
  Json::Value root;         
  
  std::ifstream is;  
  is.open (filename, std::ios::binary );    
  if (reader.parse(is, root))  
  {  
    std::string code;  
    if (!root["files"].isNull())  // 访问节点，Access an object value by name, create a null member if it does not exist.  
      code = root["uploadid"].asString();  
      
    // 访问节点，Return the member named key if it exist, defaultValue otherwise.  
    code = root.get("uploadid", "null").asString();  
  
    // 得到"files"的数组个数  
    int file_size = root["files"].size();  
  
    // 遍历数组  
    for(int i = 0; i < file_size; ++i)  
    {  
      Json::Value val_image = root["files"][i]["images"];  
      int image_size = val_image.size();  
      for(int j = 0; j < image_size; ++j)  
      {  
        std::string type = val_image[j]["type"].asString(); 
    cout<<type<<endl; 
        std::string url = val_image[j]["url"].asString(); 
      }  
    }  
  }  
  is.close();  
  return 0;  
}  

