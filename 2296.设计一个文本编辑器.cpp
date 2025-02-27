#include<string>
using namespace std;
class TextEditor {
  private:
      string currentText;
      int cursorPosition;

  public:
      TextEditor():cursorPosition(-1),currentText("") {
          
      }
      
      void addText(string text) {
          if(cursorPosition==-1) {
              currentText+=text;
              cursorPosition=currentText.size();
          } else {
              currentText.insert(cursorPosition,text);
              cursorPosition+=text.size();
          }
      }
      
      int deleteText(int k) {
        if(cursorPosition==-1) return 0;
        int left=cursorPosition-k;
        if(left<0) left=0;
        currentText.erase(left,cursorPosition-left);
        int right=cursorPosition;
        cursorPosition=left;
        return right-left;
      }
      
      string cursorLeft(int k) {
          cursorPosition-=k;
          if(cursorPosition<0) cursorPosition=0;
          int start=cursorPosition-10>=0?cursorPosition-10:0;
          return currentText.substr(start,cursorPosition-start);
      }
      
      string cursorRight(int k) {
          cursorPosition+=k;
          if(cursorPosition>currentText.size()) cursorPosition=currentText.size();
          int start=cursorPosition-10>=0?cursorPosition-10:0;
          return currentText.substr(start,cursorPosition-start);
      }
  };
  
  /**
   * Your TextEditor object will be instantiated and called as such:
   * TextEditor* obj = new TextEditor();
   * obj->addText(text);
   * int param_2 = obj->deleteText(k);
   * string param_3 = obj->cursorLeft(k);
   * string param_4 = obj->cursorRight(k);
   */