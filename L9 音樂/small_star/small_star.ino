/*小星星前奏曲*/
//請自創一段小音樂
//ppt CH11-17
//演奏速度若每分鐘180拍，則每拍時間60000/180(ms)=333ms
//演奏速度若每分鐘120拍，則每拍時間60000/120(ms)=500ms
//ppt CH11-21
#define   Buzzer   3    // 定義Buzzer腳位
 int led=8;
 int Frequency[]={262,262,392,392,440,440,392,349,349,330,330,294,294,262};//設定Do Re Mi Fa So La Si Do
 int beat[]={1,1,1,1,1,1,2,1,1,1,1,1,1,2};
  int tempo=5000;//每分鐘300拍(可用可變電阻調整)
  int duartion=60000/tempo;//計算每拍時間
void setup() { 
  pinMode(Buzzer, OUTPUT); // 設定D3為數位輸出
  pinMode(led,OUTPUT); 
 
  
    
}
void loop()
{
  for(int i=0;i < 14 ; i++) {  
     
    tone(Buzzer,Frequency[i]); //發出Frequency陣列內之聲音配合節拍
     digitalWrite(led,HIGH);
     delay(beat[i]*duartion);
     noTone(Buzzer);//停止發出聲音
     digitalWrite(led,LOW);
     delay(beat[i]*duartion);
    } 
}


    
