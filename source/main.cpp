//ÇÐ¹ø:201724425	
//ÀÌ¸§:±è¹ÎÁ¾
//github id:koust6u
#include "teststudent.h"
#include "buffile.h"
#include "length.h"
#include "fixfld.h"
#include "delim.h"
int fixlen() {
	int count, select;
	char filename[20];
	Student student;
	Student* stable[10];
	cout << "\nTesting FixedLengthTextBuffer" << endl;
	FixedFieldBuffer Buff(6);
	Buff.AddField(9);  //9 char
	Buff.AddField(11); //11 char
	Buff.AddField(4);  //1 int
	Buff.AddField(4);  //1 float
	Buff.AddField(2);  //2 char
	int result;
	int recaddr;
	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);

	while (1)
	{
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Student objects by inputing
			cout << "the number of Student object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> student;
				student.Print(cout);
				stable[i] = new Student(student);  //copy constructor should be implemented		

			}
			break;
		case 2:
			// to display the array of Student objects into screen  
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i];// operator<< (operator overloading) should be implemented
			}
			break;
		case 3:
		{

			// to write the array of Student objects into a file
			//Buff . Print (cout);
			BufferFile TestOut(Buff);
			result = TestOut.Create(filename, ios::in | ios::out);
			cout << "create file " << result << endl;
			if (!result)
			{
				cout << "Unable to create file " << filename << endl;
			}

			student.Pack(Buff);
			Buff.Print(cout);
			recaddr = TestOut.Write();
			cout << "write at " << recaddr << endl;

			for (int i = 0; i < count; i++)
			{
				stable[i]->Print(cout);
				stable[i]->Pack(Buff);
				recaddr = TestOut.Write();
				cout << "Student R[" << i << "] at recaddr " << recaddr << endl;

				delete(stable[i]);//return the object created by new()
			}
			Buff.testPrint();
			break;
		}
		case 4:
		{
			// to read the array of Student records from the file
			BufferFile TestIn(Buff);
			TestIn.Open(filename, ios::in);
			//result = TestIn . ReadHeader ();
			//cout <<"read header "<<result<<endl;
			TestIn.Read(recaddr);
			student.Unpack(Buff);
			char msg[20] = "First record: ";
			student.Print(cout, msg);


			for (int i = 0; i < count; i++)
			{
				stable[i] = new Student();
				recaddr = TestIn.Read();
				stable[i]->Unpack(Buff);
				stable[i]->Print(cout);
			}
			if (result != -1) cout << "Read past end of file! Error." << endl;
			else cout << "Read past end of file failed! Correct." << endl;

			break;
		}
		default:
			// others
			return 0;

			//*/
		}
	}

	return 1;
}

int varlen() {
	int count, select;
	char filename[20];
	Student student;
	Student* stable[10];
	cout << "\nTesting LengthTextBuffer" << endl;
	LengthFieldBuffer Buff;
	int result;
	int recaddr;
	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);

	while (1)
	{
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Student objects by inputing
			cout << "the number of Student object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> student;
				student.Print(cout);
				stable[i] = new Student(student);  //copy constructor should be implemented		

			}
			break;
		case 2:
			// to display the array of Student objects into screen  
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i];// operator<< (operator overloading) should be implemented
			}
			break;
		case 3:
		{

			// to write the array of Student objects into a file
			//Buff . Print (cout);
			BufferFile TestOut(Buff);
			result = TestOut.Create(filename, ios::in | ios::out);
			cout << "create file " << result << endl;
			if (!result)
			{
				cout << "Unable to create file " << filename << endl;
			}
			/*
			result = TestOut.Open(myfile, ios::in | ios::out);
			cout << "open file " << result << endl;
			if (!result)
			{
				cout << "Unable to open file " << myfile << endl;
				return;
			}
			*/
			//}
			student.Pack(Buff);
			Buff.Print(cout);
			recaddr = TestOut.Write();
			cout << "write at " << recaddr << endl;

			for (int i = 0; i < count; i++)
			{
				stable[i]->Print(cout);
				stable[i]->Pack(Buff);
				recaddr = TestOut.Write();
				cout << "Student R[" << i << "] at recaddr " << recaddr << endl;

				delete(stable[i]);//return the object created by new()
			}
			break;
		}
		case 4:
		{
			// to read the array of Student records from the file
			BufferFile TestIn(Buff);
			TestIn.Open(filename, ios::in);
			//result = TestIn . ReadHeader ();
			//cout <<"read header "<<result<<endl;
			TestIn.Read(recaddr);
			student.Unpack(Buff);
			char msg[20] = "First record: ";
			student.Print(cout, msg);


			for (int i = 0; i < count; i++)
			{
				stable[i] = new Student();
				recaddr = TestIn.Read();
				stable[i]->Unpack(Buff);
				stable[i]->Print(cout);
			}
			if (result != -1) cout << "Read past end of file! Error." << endl;
			else cout << "Read past end of file failed! Correct." << endl;

			break;
		}
		default:
			// others
			return 0;

			//*/
		}
	}

	return 1;
}
int vardel() {
	int count, select;
	char filename[20];
	Student student;
	Student* stable[10];
	cout << "\nTesting DelimTextBuffer" << endl;
	DelimFieldBuffer Buff;
	int result;
	int recaddr;
	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);

	while (1)
	{
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Student objects by inputing
			cout << "the number of Student object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> student;
				student.Print(cout);
				stable[i] = new Student(student);  //copy constructor should be implemented		

			}
			break;
		case 2:
			// to display the array of Student objects into screen  
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i];// operator<< (operator overloading) should be implemented
			}
			break;
		case 3:
		{

			// to write the array of Student objects into a file
			//Buff . Print (cout);
			BufferFile TestOut(Buff);
			result = TestOut.Create(filename, ios::in | ios::out);
			cout << "create file " << result << endl;
			if (!result)
			{
				cout << "Unable to create file " << filename << endl;
			}
			/*
			result = TestOut.Open(myfile, ios::in | ios::out);
			cout << "open file " << result << endl;
			if (!result)
			{
				cout << "Unable to open file " << myfile << endl;
				return;
			}
			*/
			//}
			student.Pack(Buff);
			Buff.Print(cout);
			recaddr = TestOut.Write();
			cout << "write at " << recaddr << endl;

			for (int i = 0; i < count; i++)
			{
				stable[i]->Print(cout);
				stable[i]->Pack(Buff);
				recaddr = TestOut.Write();
				cout << "Student R[" << i << "] at recaddr " << recaddr << endl;

				delete(stable[i]);//return the object created by new()
			}
			break;
		}
		case 4:
		{
			// to read the array of Student records from the file
			BufferFile TestIn(Buff);
			TestIn.Open(filename, ios::in);
			//result = TestIn . ReadHeader ();
			//cout <<"read header "<<result<<endl;
			TestIn.Read(recaddr);
			student.Unpack(Buff);
			char msg[20] = "First record: ";
			student.Print(cout, msg);


			for (int i = 0; i < count; i++)
			{
				stable[i] = new Student();
				recaddr = TestIn.Read();
				stable[i]->Unpack(Buff);
				stable[i]->Print(cout);
			}
			if (result != -1) cout << "Read past end of file! Error." << endl;
			else cout << "Read past end of file failed! Correct." << endl;

			break;
		}
		default:
			// others
			exit(0);
			break;

			//*/
		}
	}

	return 1;
}

int main(int argc, char** argv)
{
	//fixlen();
	varlen();
	//vardel();
}
