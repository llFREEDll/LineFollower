   //las variables motorxx sirven para dar 5v
   // y GND a cada uno de los dos motores
   //dependiendo del caso
   // las variables pwmMotorX sirven para definir
   //la velocidad a la que se movera el motor
   //es un rango entre 0 - 255  
   
    byte motor11 = 9 ,motor12 = 2, 
    motor21 = 3, motor22 = 4,
    pwmMotorA = 5, pwmMotorB = 6,
    //sensores 
    //estas variables reciben el dato obtenido
    //por los dos sensores ya sea 1 para
    //superficies oscuras o 0 para cualquier otro tipo    
    
    sensorA = 7, sensorB = 8, valorSensorA  = 0 ,valorSensorB = 0 , 
    sensorC = 11, sensorD = 10, valorSensorC = 0 ,valorSensorD = 0 ;

    
 

void setup() {
  //motores
  //se declara todo como salidas ya que vamos a enviar informacion
  
  pinMode(motor11, OUTPUT);
  pinMode(motor12, OUTPUT);
  pinMode(motor21, OUTPUT);
  pinMode(motor22, OUTPUT);
  pinMode(pwmMotorA, OUTPUT);
  pinMode(pwmMotorB, OUTPUT);

  //sensores
  //sperficie negra = 1
  //se declaran como entrada porque recibimos informacion
  
  pinMode(sensorA , INPUT);
  pinMode(sensorB , INPUT);
  pinMode(sensorC , INPUT);
  pinMode(sensorD , INPUT);

  
}

int velocidad = 85, delay1 = 28 , delay2 = 130;
void loop() {
   
  valorSensorA = digitalRead(sensorA);
  valorSensorB = digitalRead(sensorB);
  valorSensorC = digitalRead(sensorC);
  valorSensorD = digitalRead(sensorD);

   if(valorSensorA == 1 && valorSensorB == 1 && valorSensorC == 1 && valorSensorD == 1){

      digitalWrite(motor11,LOW); 
      digitalWrite(motor12,LOW);    
      digitalWrite(motor21,LOW); 
      digitalWrite(motor22,LOW);
    
    }
    else if(valorSensorA == 0 && valorSensorB == 0 && valorSensorC == 1 && valorSensorD == 0){
        
        Serial.println("Sensor C");
        digitalWrite(motor11,LOW); 
        digitalWrite(motor12,LOW);    
        digitalWrite(motor21,LOW); 
        digitalWrite(motor22,LOW);
        
        digitalWrite(motor21,HIGH); 
        digitalWrite(motor22,LOW);  
        analogWrite(pwmMotorA, velocidad);
        
        delay(delay2);
    
      }
      else if(valorSensorA == 0 && valorSensorB == 0 && valorSensorC == 0 && valorSensorD == 1){
      
        Serial.println("Sensor D");
        digitalWrite(motor11,LOW); 
        digitalWrite(motor12,LOW);    
        digitalWrite(motor21,LOW); 
        digitalWrite(motor22,LOW);
        
        digitalWrite(motor11,HIGH); 
        digitalWrite(motor12,LOW);  
        
        analogWrite(pwmMotorB, velocidad);
        
        delay(delay2);
      
      }
   else if(valorSensorA == 1 
   && valorSensorB == 0 && valorSensorC == 0 && valorSensorD == 0
   ){  
    
    Serial.println("Sensor A");
    //apagar el motor
    digitalWrite(motor11,LOW); 
    digitalWrite(motor12,LOW);    
    digitalWrite(motor21,LOW); 
    digitalWrite(motor22,LOW);

    //un pin del motor se declara low y otro high para hacer la funcion
    // voltaje/tierra, si se usa high/high se quema el motor 
    digitalWrite(motor21,HIGH); 
    digitalWrite(motor22,LOW);  
    //se declara en los pines pwm la velocidad maxima de los motores
    analogWrite(pwmMotorA, velocidad);
    
    delay(delay1);

    
    
    }else if (
      valorSensorA == 0 &&
      valorSensorB == 1 
    && valorSensorC == 0 && valorSensorD == 0
){
      
      Serial.println("Sensor B");

      digitalWrite(motor11,LOW); 
      digitalWrite(motor12,LOW);    
      digitalWrite(motor21,LOW); 
      digitalWrite(motor22,LOW);
      
      digitalWrite(motor11,HIGH); 
      digitalWrite(motor12,LOW);  

      analogWrite(pwmMotorB, velocidad);
      
      delay(delay1);
  
      
      
      }
      else{

        Serial.print(valorSensorD);
        Serial.print(valorSensorB);
        Serial.print(valorSensorA);
        Serial.println(valorSensorC);
        

        digitalWrite(motor11,HIGH); 
        digitalWrite(motor12,LOW); 
        digitalWrite(motor21,HIGH); 
        digitalWrite(motor22,LOW); 
   
        analogWrite(pwmMotorA, velocidad);
        analogWrite(pwmMotorB, velocidad);
        
        }
  

}
