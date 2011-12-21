
String test="$GPGGA,170834,4124.8963,N,08151.6838,W,1,05,1.5,280.2,M,-34.0,M,,,*59";
String splitString(String s, char parser,int index);
void setup(){
  Serial.begin(9600);  

}

void loop(){
  int c=0;
  String marker=splitString(test,',',0);
  String time = splitString(test,',',1);
  String ns = splitString(test,',',3);
  Serial.println(marker);
  Serial.println(time);
  Serial.println(ns);
}

String splitString(String s, char parser,int index){
  String rs='\0';
  int parserIndex = index;
  int parserCnt=0;
  int rFromIndex=0, rToIndex=-1;

  while(index>=parserCnt){
    rFromIndex = rToIndex+1;
    rToIndex = s.indexOf(parser,rFromIndex);

    if(index == parserCnt){
      if(rToIndex == 0 || rToIndex == -1){
        return '\0';
      }
      return s.substring(rFromIndex,rToIndex);
    }
    else{
      parserCnt++;
    }

  }
  return rs;
}


