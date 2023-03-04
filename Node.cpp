#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Node
{
private:
	string adminName;
	string adminPassword;
	Node *admin_head;
	Node *admin_tail;
	int serviceId;
	string serviceName;
	string serviceCost;
	Node *next;
	Node *service_head;
	Node *service_tail;
	int customerId;
	string customerName;
	string customerPhoneNo;
	string customerAddress;
	string customerEmail;
	Node *customer_head;
	Node *customer_tail;
	string invoiceDate;
	string invoiceStatus;
	string invoiceTime;
	Node *invoice_head;
	Node *invoice_tail;

public:
	Node()
	{
		adminName = "";
		adminPassword = "";
		admin_head = NULL;
		admin_tail = NULL;
		serviceId = 0;
		serviceName = "";
		serviceCost = "";
		service_head = NULL;
		service_tail = NULL;
		customerName = "";
		customerPhoneNo = "";
		customerAddress = "";
		customerEmail = "";
		customerId = 0;
		customer_head = NULL;
		customer_tail = NULL;
		invoiceDate = "";
		invoiceStatus = "";
		invoiceTime = "";
		next = NULL;
		invoice_head = NULL;
		invoice_tail = NULL;
	}
	bool isEmpty()
	{
		if (admin_head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isEmpty1()
	{
		if (service_head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isEmpty2()
	{
		if (customer_head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isEmpty3()
	{
		if (invoice_head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void CreateAdminAccount()
	{
		cout << "==============================" << endl;
		cout << "Please Create Your Account : " << endl;
		cout << "==============================" << endl;
		cin.ignore();
		cout << "Enter Your Username : " << endl;
		getline(cin, adminName);
		cout << "Enter Your Password : " << endl;
		getline(cin, adminPassword);
		if (isEmpty())
		{
			Node *newNode = new Node();
			newNode->adminName = adminName;
			newNode->adminPassword = adminPassword;
			admin_head = newNode;
			admin_tail = newNode;
		}
		else
		{
			Node *newNode = new Node();
			newNode->adminName = adminName;
			newNode->adminPassword = adminPassword;
			admin_tail->next = newNode;
			admin_tail = newNode;
		}
		cout << "================================" << endl;
		cout << "Account Created Successfully! " << endl;
		cout << "================================" << endl;
	}

	void loginAdmin()
	{
		Node *temp = admin_head;
		Node *newNode1 = new Node();
		if (isEmpty())
		{
			cout << "No Account Found!" << endl;
		}
		else
		{
			cout << "==============================" << endl;
			cout << "Login Admin : " << endl;
			cout << "==============================" << endl;
			cin.ignore();
			cout << "Enter Your Username : " << endl;
			getline(cin, newNode1->adminName);
			cout << "Enter Your Password: " << endl;
			cin >> newNode1->adminPassword;
			while (temp != NULL)
			{
				if (temp->adminName == newNode1->adminName && temp->adminPassword == newNode1->adminPassword)
				{
					Menu();
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
	}

	void Menu()
	{
		system("cls");
		cout << "==============================" << endl;
		cout << "Welcome To The Menu : " << endl;
		cout << "==============================" << endl;
		int choice;
		cout << "1-Manage Services " << endl;
		cout << "2-Manage Customers " << endl;
		cout << "3-Manage Invoices  " << endl;
		cout << "4-Log out " << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			ManageServices();
			break;
		case 2:
			ManageCustomers();
			break;
		case 3:
			ManageInvoices();
			break;
		case 4:
			cout << "Logging out........." << endl;
			break;
		default:
			cout << "Wrong Choice..!" << endl;
			Menu();
			break;
		}
	}
	void ManageServices()
	{
		cout << "==============================" << endl;
		cout << "Welcome to Manage Services : " << endl;
		cout << "==============================" << endl;
		int choice;
		cout << "1-Add Services " << endl;
		cout << "2-Delete Services " << endl;
		cout << "3-Update Services " << endl;
		cout << "4-Search Services " << endl;
		cout << "5-Show All Records Of A Services " << endl;
		cout << "6-Back to Menu " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			Add_Services();
			break;
		case 2:
			Delete_Services();
			break;
		case 3:
			update_Services();
			break;
		case 4:
			Search_Services();
			break;
		case 5:
			Show_Services();
			break;
		case 6:
			Menu();
			break;
		default:
			cout << "Wrong Choice!" << endl;
			ManageServices();
			break;
		}
	}

	void Add_Services()
	{
		cout << "==============================" << endl;
		cout << "Enter Service Id : " << endl;
		cin >> serviceId;
		cin.ignore();
		cout << "Enter Service Name : " << endl;
		getline(cin, serviceName);
		cout << "Enter Service Cost : " << endl;
		getline(cin, serviceCost);
		if (isEmpty1())
		{
			Node *newNode = new Node();
			newNode->serviceId = serviceId;
			newNode->serviceName = serviceName;
			newNode->serviceCost = serviceCost;
			service_head = newNode;
			service_tail = newNode;
		}

		else
		{
			Node *newNode = new Node();
			newNode->serviceId = serviceId;
			newNode->serviceName = serviceName;
			newNode->serviceCost = serviceCost;
			service_tail->next = newNode;
			service_tail = newNode;
		}
		cout << "==============================" << endl;
		cout << "Service Added Successfully!!!!" << endl;
		ManageServices();
	}
	void Delete_Services()
	{
		cout << "======================================" << endl;
		if (isEmpty1())
		{
			cout << "No Services Available To Be Deleted!!!!" << endl;
			cout << "======================================" << endl;
		}

		else
		{
			int value;
			cout << "Enter Id Of Service To Be Deleted : " << endl;
			cin >> value;
			Node *current = service_head;
			Node *prev = NULL;
			while (current != NULL)
			{

				if (current->serviceId == value)
				{
					if (current == service_head)
					{

						service_head = current->next;
						delete current;
					}
					else if (current == service_tail)
					{
						service_tail = prev;
						prev->next = NULL;
						delete current;
					}
					else
					{
						prev->next = current->next;
						delete current;
					}
					break;
				}
				else
				{
					prev = current;
					current = current->next;
				}
			}
		}
		ManageServices();
	}

	void update_Services()
	{
		cout << "======================================" << endl;
		if (isEmpty1())
		{
			cout << "No Services Available To Be Updated!!!" << endl;
			cout << "======================================" << endl;
		}
		else
		{
			int id;
			cout << "Enter Id Of Service To Be Updated : " << endl;
			cin >> id;
			Node *temp = service_head;
			while (temp != NULL)
			{
				if (temp->serviceId == id)
				{
					cout << "Enter Service Id: " << endl;
					cin >> temp->serviceId;
					cout << "Enter Service Name : " << endl;
					cin >> temp->serviceName;
					cout << "Enter Service Cost : " << endl;
					cin >> temp->serviceCost;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
		cout << "====================================" << endl;
		ManageServices();
	}
	void Show_Services()
	{
		system("cls");
		Node *p = service_head;
		if (p == NULL)
		{
			cout << "No Record "
				 << "Available.....!\n";
		}
		else
		{
			cout << "All Services : " << endl;
			cout << "======================================" << endl;
			while (p != NULL)
			{

				cout << "Service Id : " << p->serviceId << endl;
				cout << "Service Name : " << p->serviceName << endl;
				cout << "Service Cost : " << p->serviceCost << endl;
				p = p->next;
				cout << "======================================" << endl;
			}
		}

		ManageServices();
	}
	void Search_Services()
	{
		cout << "======================================" << endl;
		if (isEmpty1())
		{
			cout << "No Records Available To Be Searched.....!" << endl;
		}
		else
		{
			Node *p = service_head;
			int r;
			cout << "Enter ID Of The Service To Be Searched : " << endl;
			cin >> r;
			while (p != NULL)
			{
				if (p->serviceId == r)
				{
					cout << "Search Found : " << endl;
					cout << "======================================" << endl;
					cout << "Service Id : " << p->serviceId << endl;
					cout << "Service Name : " << p->serviceName << endl;
					cout << "Service Cost : " << p->serviceCost << endl;
					break;
				}
				else
				{
					p = p->next;
				}
			}
		}
		cout << "======================================" << endl;

		ManageServices();
	}

	void ManageCustomers()
	{
		cout << "==============================" << endl;
		cout << "Welcome to Manage Customers : " << endl;
		cout << "==============================" << endl;
		int choice;
		cout << "1- Add A Customer Against A Service : " << endl;
		cout << "2- Update Customer Information :" << endl;
		cout << "3- Delete Customer Information :" << endl;
		cout << "4- Search Customer Information :" << endl;
		cout << "5- Display All Customers Information :" << endl;
		cout << "6- Back to Menu : " << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			AddACustomerAgainstService();
			break;
		case 2:
			UpdateInformationOfACustomer();
			break;

		case 3:
			DeleteInformationOfACustomer();
			break;
		case 4:
			SearchCustomerRecord();
			break;
		case 5:
			ShowCustomerRecord();
			break;
		case 6:
			Menu();
			break;
		default:
			cout << "Wrong Choice..!" << endl;
			ManageCustomers();
			break;
		}
	}

	void AddACustomerAgainstService()
	{
		cout << "==============================" << endl;
		Node *temp = service_head;
		cout << "Enter Customer Id : " << endl;
		cin >> customerId;
		cin.ignore();
		cout << "Enter Customer Name : " << endl;
		getline(cin, customerName);
		cout << "Enter Customer Address : " << endl;
		getline(cin, customerAddress);
		cout << "Enter Customer Phone Number : " << endl;
		getline(cin, customerPhoneNo);
		cout << "Enter Customer Email : " << endl;
		getline(cin, customerEmail);

		if (isEmpty1())
		{
			cout << "========================================" << endl;
			cout << "No Services Available To Enroll........." << endl;
			ManageCustomers();
		}

		else
		{
			cout << "Available Services : " << endl;
			cout << "======================================" << endl;
			while (temp != NULL)
			{
				cout << "Service Id : " << temp->serviceId << endl;
				cout << "Service Name : " << temp->serviceName << endl;
				cout << "Service Cost : " << temp->serviceCost << endl;
				temp = temp->next;
				cout << "======================================" << endl;
			}
		}
		cout << "Enter Service Id To Add : " << endl;
		int id;
		cin >> id;
		Node *temp1 = service_head;
		Node *temp2 = customer_head;
		while (temp1 != NULL)
		{
			if (temp1->serviceId == id)
			{
				temp2 = temp1;
				break;
			}
			else
			{
				temp1 = temp1->next;
			}
		}
		if (isEmpty2())
		{
			Node *newNode = new Node;
			newNode->customerId = customerId;
			newNode->customerName = customerName;
			newNode->customerAddress = customerAddress;
			newNode->customerPhoneNo = customerPhoneNo;
			newNode->customerEmail = customerEmail;
			newNode->serviceId = id;
			newNode->serviceName = temp2->serviceName;
			newNode->serviceCost = temp2->serviceCost;
			customer_head = newNode;
			customer_tail = newNode;
		}
		else
		{
			Node *newNode = new Node;
			newNode->customerId = customerId;
			newNode->customerName = customerName;
			newNode->customerAddress = customerAddress;
			newNode->customerPhoneNo = customerPhoneNo;
			newNode->customerEmail = customerEmail;
			newNode->serviceId = id;
			newNode->serviceName = temp2->serviceName;
			newNode->serviceCost = temp2->serviceCost;
			customer_tail->next = newNode;
			customer_tail = newNode;
		}
		cout << "======================================" << endl;
		cout << "Customer Added Successfully....!" << endl;
		ManageCustomers();
	}
	void UpdateInformationOfACustomer()
	{
		cout << "======================================" << endl;
		if (isEmpty2())
		{
			cout << "No Customers Available To Be Updated........." << endl;
		}
		else
		{
			int Id;
			cout << "Enter Customer ID To Be Updated: " << endl;
			cin >> Id;
			Node *temp = customer_head;
			while (temp != NULL)
			{
				if (temp->customerId == Id)
				{
					cout << "Enter New Customer ID : " << endl;
					cin >> customerId;
					cin.ignore();
					cout << "Enter New Customer Name : " << endl;
					getline(cin, temp->customerName);
					cout << "Enter New Customer Phone No : " << endl;
					getline(cin, temp->customerPhoneNo);
					cout << "Enter New Customer Address : " << endl;
					getline(cin, temp->customerAddress);
					cout << "Enter New Customer Email : " << endl;
					getline(cin, temp->customerEmail);
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
		cout << "======================================" << endl;
		ManageCustomers();
	}
	void ShowCustomerRecord()
	{
		system("cls");
		Node *temp1 = customer_head;
		if (isEmpty2())
		{
			cout << "No Records Available.....!" << endl;
		}
		else
		{
			cout << "All Customer Records : " << endl;
			cout << "======================================" << endl;
			while (temp1 != NULL)
			{
				cout << "Service Id : " << temp1->serviceId << endl;
				cout << "Service Name : " << temp1->serviceName << endl;
				cout << "Service Cost : " << temp1->serviceCost << endl;
				cout << "Customer Id : " << temp1->customerId << endl;
				cout << "Customer Name : " << temp1->customerName << endl;
				cout << "Customer Address : " << temp1->customerAddress << endl;
				cout << "Customer Phone No : " << temp1->customerPhoneNo << endl;
				cout << "Customer Email : " << temp1->customerEmail << endl;
				temp1 = temp1->next;
				cout << "======================================" << endl;
			}
		}

		ManageCustomers();
	}
	void SearchCustomerRecord()
	{
		cout << "==================================================" << endl;
		if (isEmpty2())
		{
			cout << "No Records Available To Be Searched......!!!" << endl;
		}
		else
		{
			Node *temp = customer_head;
			int id;
			cout << "Enter Customer ID to Be searched : " << endl;
			cin >> id;
			while (temp != NULL)
			{
				if (temp->customerId == id)
				{
					cout << "Search Found" << endl;
					cout << "==================================================" << endl;
					cout << "Service Id : " << temp->serviceId << endl;
					cout << "Service Name : " << temp->serviceName << endl;
					cout << "Service Cost : " << temp->serviceCost << endl;
					cout << "Customer Id : " << temp->customerId << endl;
					cout << "Customer Name : " << temp->customerName << endl;
					cout << "Customer Phone No : " << temp->customerPhoneNo << endl;
					cout << "Customer Address : " << temp->customerAddress << endl;
					cout << "Customer Email : " << temp->customerEmail << endl;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
		cout << "==================================================" << endl;

		ManageCustomers();
	}
	void DeleteInformationOfACustomer()
	{
		cout << "======================================" << endl;
		if (isEmpty2())
		{
			cout << "No Customers Available To Be Deleted........." << endl;
		}
		else
		{
			int Id;
			cout << "Enter Customer ID To Be Deleted: " << endl;
			cin >> Id;
			Node *temp = customer_head;
			Node *prev1 = NULL;
			while (temp != NULL)
			{
				if (temp->customerId == Id)
				{
					if (temp == customer_head)
					{
						customer_head = temp->next;
					}
					else if (temp == customer_tail)
					{
						customer_tail = prev1;
						customer_tail->next = NULL;
					}
					else
					{
						prev1->next = temp->next;
					}
					delete temp;
					break;
				}
				else
				{
					prev1 = temp;
					temp = temp->next;
				}
			}
		}
		cout << "======================================" << endl;
		ManageCustomers();
	}
	void ManageInvoices()
	{
		cout << "===============================" << endl;
		cout << "Welcome To Invoice Management" << endl;
		cout << "===============================" << endl;
		cout << "1.Add Invoice" << endl;
		cout << "2.Store Invoice In A File" << endl;
		cout << "3.show Invoice" << endl;
		cout << "4.Update Invoice" << endl;
		cout << "5.Search Invoice" << endl;
		cout << "6.Back to Menu" << endl;
		cout << "===============================" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			AddInvoice();
			break;
		case 2:
			GenerateInvoiceInAFile();
			break;
		case 3:
			showInvoice();
			break;
		case 4:
			UpdateInvoice();
			break;
		case 5:
			searchInvoice();
		case 6:
			Menu();
		default:
			cout << "Wrong Choice" << endl;
			ManageInvoices();
		}
	}
	void AddInvoice()
	{
		cin.ignore();
		cout << "Enter Invoice Date : " << endl;
		getline(cin, invoiceDate);
		cout << "Enter Invoice Status : " << endl;
		getline(cin, invoiceStatus);
		cout << "Enter Invoice Time : " << endl;
		getline(cin, invoiceTime);
		if (isEmpty2())
		{
			cout << "No Customers Available To Be Invoiced....!" << endl;
		}
		else
		{
			cout << "===============================================" << endl;
			cout << "Available Customers With Services : " << endl;
			Node *temp = customer_head;
			while (temp != NULL)
			{
				cout << "Customer Id : " << temp->customerId << endl;
				cout << "Customer Name : " << temp->customerName << endl;
				cout << "Customer Phone No : " << temp->customerPhoneNo << endl;
				cout << "Customer Address : " << temp->customerAddress << endl;
				cout << "Customer Email : " << temp->customerEmail << endl;
				cout << "Service Id : " << temp->serviceId << endl;
				cout << "Service Name : " << temp->serviceName << endl;
				cout << "Service Cost : " << temp->serviceCost << endl;
				temp = temp->next;
			}
			cout << "===============================================" << endl;
			cout << "Enter Customer ID To Make Invoice : " << endl;
			int Id;
			cin >> Id;
			Node *temp1 = customer_head;
			Node *temp2 = invoice_head;
			while (temp1 != NULL)
			{
				if (temp1->customerId == Id)
				{
					temp2 = temp1;
					break;
				}
				else
				{
					temp1 = temp1->next;
				}
			}
			if (isEmpty3())
			{
				Node *newNode = new Node();
				newNode->customerId = temp2->customerId;
				newNode->customerName = temp2->customerName;
				newNode->customerPhoneNo = temp2->customerPhoneNo;
				newNode->customerAddress = temp2->customerAddress;
				newNode->customerEmail = temp2->customerEmail;
				newNode->serviceId = temp2->serviceId;
				newNode->serviceName = temp2->serviceName;
				newNode->serviceCost = temp2->serviceCost;
				newNode->invoiceDate = invoiceDate;
				newNode->invoiceStatus = invoiceStatus;
				newNode->invoiceTime = invoiceTime;
				invoice_head = newNode;
				invoice_tail = newNode;
			}
			else
			{
				Node *newNode = new Node();
				newNode->customerId = temp2->customerId;
				newNode->customerName = temp2->customerName;
				newNode->customerPhoneNo = temp2->customerPhoneNo;
				newNode->customerAddress = temp2->customerAddress;
				newNode->customerEmail = temp2->customerEmail;
				newNode->serviceId = temp2->serviceId;
				newNode->serviceName = temp2->serviceName;
				newNode->serviceCost = temp2->serviceCost;
				newNode->invoiceDate = invoiceDate;
				newNode->invoiceStatus = invoiceStatus;
				newNode->invoiceTime = invoiceTime;
				invoice_tail->next = newNode;
				invoice_tail = newNode;
			}
		}
		cout << "==================================================" << endl;
		cout << "Invoice Added Successfully....." << endl;
		cout << "==================================================" << endl;
		ManageInvoices();
	}
	void UpdateInvoice()
	{
		cout << "========================================" << endl;
		if (isEmpty3())
		{
			cout << "No Invoices Available To Be Updated........!!" << endl;
		}
		else
		{

			int Id;
			cout << "Enter Customer ID To Update Invoice: " << endl;
			cin >> Id;
			Node *temp = invoice_head;
			while (temp != NULL)
			{
				if (temp->customerId == Id)
				{
					cin.ignore();
					cout << "Enter New Invoice Date : " << endl;
					getline(cin, temp->invoiceDate);
					cout << "Enter New Invoice Time : " << endl;
					getline(cin, temp->invoiceTime);
					cout << "Enter New Invoice Status : " << endl;
					getline(cin, temp->invoiceStatus);
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
		ManageInvoices();
	}
	void searchInvoice()
	{
		cout << "========================================" << endl;
		if (isEmpty3())
		{
			cout << "No Invoices Available To Be Searched........!!" << endl;
		}
		else
		{
			int Id;
			cout << "Enter Customer ID To Search Invoice: " << endl;
			cin >> Id;
			Node *temp = invoice_head;
			while (temp != NULL)
			{
				if (temp->customerId == Id)
				{
					cout << "========================================" << endl;
					cout << "Invoice Details : " << endl;
					cout << "========================================" << endl;
					cout << "Invoice Date : " << temp->invoiceDate << endl;
					cout << "Invoice Time : " << temp->invoiceTime << endl;
					cout << "Invoice Status : " << temp->invoiceStatus << endl;
					cout << "Service Id : " << temp->serviceId << endl;
					cout << "Service Name : " << temp->serviceName << endl;
					cout << "Service Cost : " << temp->serviceCost << endl;
					cout << "Customer Id : " << temp->customerId << endl;
					cout << "Customer Name : " << temp->customerName << endl;
					cout << "Customer Phone No : " << temp->customerPhoneNo << endl;
					cout << "Customer Address : " << temp->customerAddress << endl;
					cout << "Customer Email : " << temp->customerEmail << endl;
					cout << "========================================" << endl;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
		ManageInvoices();
	}
	void GenerateInvoiceInAFile()
	{
		ofstream outfile;
		outfile.open("Invoice.csv");
		Node *temp = invoice_head;
		while (temp != NULL)
		{
			if (outfile.is_open())
			{
				outfile << "Invoice Date : " << temp->invoiceDate << endl;
				outfile << "Invoice Status : " << temp->invoiceStatus << endl;
				outfile << "Invoice Time : " << temp->invoiceTime << endl;
				outfile << "Service Id : " << temp->serviceId << endl;
				outfile << "Service Name : " << temp->serviceName << endl;
				outfile << "Service Cost : " << temp->serviceCost << endl;
				outfile << "Customer Id : " << temp->customerId << endl;
				outfile << "Customer Name : " << temp->customerName << endl;
				outfile << "Customer Phone No : " << temp->customerPhoneNo << endl;
				outfile << "Customer Address : " << temp->customerAddress << endl;
				outfile << "Customer Email : " << temp->customerEmail << endl;
			}
			else
			{
				cout << "File Not Opened" << endl;
			}
			temp = temp->next;
		}
		outfile.close();

		ManageInvoices();
	}

	void showInvoice()
	{
		Node *temp = invoice_head;
		if (isEmpty3())
		{
			cout << "No Invoices Available....!" << endl;
		}
		else
		{
			cout << "===============================================" << endl;
			while (temp != NULL)
			{
				cout << "Invoice Date : " << temp->invoiceDate << endl;
				cout << "Invoice Status : " << temp->invoiceStatus << endl;
				cout << "Invoice Time : " << temp->invoiceTime << endl;
				cout << "Service Id : " << temp->serviceId << endl;
				cout << "Service Name : " << temp->serviceName << endl;
				cout << "Service Cost : " << temp->serviceCost << endl;
				cout << "Customer Id : " << temp->customerId << endl;
				cout << "Customer Name : " << temp->customerName << endl;
				cout << "Customer Phone No : " << temp->customerPhoneNo << endl;
				cout << "Customer Address : " << temp->customerAddress << endl;
				cout << "Customer Email : " << temp->customerEmail << endl;
				cout << "===============================================" << endl;

				temp = temp->next;
			}
		}

		ManageInvoices();
	}
};

int main()
{
	Node n;
	int choice;
	cout << "\n\n\t\t\t===========================================================" << endl;
	cout << "\n\n\t\t\t=============TRAVELING AGENCY SYSTEM========================" << endl;
	cout << "\n\n\t\t\t===========================================================" << endl;
	while (true)
	{
		cout << "1.Create Admin Account" << endl;
		cout << "2.Admin Login" << endl;
		cout << "3.Exit" << endl;
		cout << "Enter Your Choice : " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			n.CreateAdminAccount();
			break;
		case 2:
			n.loginAdmin();
			break;
		case 3:
			cout << "Goodbye......." << endl;
			exit(0);
			break;
		default:
			cout << "Invalid Choice" << endl;
		}
	}
}
