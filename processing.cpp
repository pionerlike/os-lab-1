#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main()
{

  pid_t child;

  if ((child = fork()) < 0)
  {
    cout << "Ошибка"; /* обработать ошибку */
  }

  else if (child == 0)  /* это новый процесс */
  {
    cout << "Процесс №1 c ID : " << getpid() << " порожденный процессом родителем с ID (?): " << getppid() << endl;

    if ((child = fork()) < 0)
    {
      cout << "Ошибка"; /* обработать ошибку */
    }

    else if (child == 0)  /* это новый процесс */
    {
      cout << "Процесс №2 c ID : " << getpid() << " порожденный родителем №1 с ID : " << getppid() << endl;
      
      if ((child = fork()) < 0)
      {
        cout << "Ошибка"; /* обработать ошибку */
      }
      else if (child == 0)  /* это новый процесс */
      {
        cout << "Процесс №4 c ID : " << getpid() << " порожденный родителем №2 с ID : " << getppid() << endl;
        cout << "Процесс №4 завершает работу" << endl;
        exit(0);
      }
      sleep(1);
      if ((child = fork()) < 0)
      {
        cout << "Ошибка"; /* обработать ошибку */
      }
      else if (child == 0)  /* это новый процесс */
      {
        cout << "Процесс №5 c ID : " << getpid() << " порожденный родителем №2 с ID : " << getppid() << endl;
        cout << "Процесс №5 завершает работу" << endl;
        exit(0);
      }
      exit(0);
      sleep(1);   
    }
    else 
    {
      //создание 3 ветви
         if ((child = fork()) < 0)
      {
        cout << "Ошибка"; /* обработать ошибку */
      }

      else if (child == 0)  /* это новый процесс */
      {
        cout << "Процесс №3 c ID : " << getpid() << " порожденный родителем №1 с ID : " << getppid() << endl;
        sleep(1);
        //6-проц
           if ((child = fork()) < 0)
        {
          cout << "Ошибка"; /* обработать ошибку */
        }
        else if (child == 0)  /* это новый процесс */
        {
          cout << "Процесс №6 c ID : " << getpid() << " порожденный родителем №3 с ID : " << getppid() << endl;
             cout << "Процесс №6 завершает работу" << endl;
          exit(0);
        }
        sleep(1);
        //7-проц
          if ((child = fork()) < 0)
        {
          cout << "Ошибка"; /* обработать ошибку */
        }
        else if (child == 0)  /* это новый процесс */
        {
          cout << "Процесс №7 c ID : " << getpid() << " порожденный родителем №3 с ID : " << getppid() << endl;
            cout << "Процесс №7 завершает работу" << endl;
          exit(0);
        }      
      
        sleep(1);
      }
      else
      {
          execlp("ps", "ps", "-o", "pid,ppid,pgrp,session,tpgid,comm",NULL);
        sleep(1);  
    }
    
    sleep(1);
    }
     
    
      
  }
  else
  {
      sleep(1);
      
  }
  return 0;
}
