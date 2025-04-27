#pragma once
class Computer
{
	static int nextSerialNumber;

	int serialNumber;
    char* brand;
	char* processor;
	int video;
	int hardDrive;
	double weight;
	double batteryLife;
	double price;
	int quantity=0;

	void copyFrom(const Computer& other);
	void free();

public:
	Computer();
	Computer(const char* brand, const char* processor, int video, int hardDrive, double weight, double batteryLife, double price);
	Computer(const Computer& other);
	Computer& operator=(const Computer& other);
	~Computer();
	
	void setQuantity(int quantity); 
	void printComputer() const;

	const char* getBrand() const;
	const char* getProcessor() const;
	int getSerialNumber() const;
	int getVideo() const;
	int getHardDrive() const;
	double getWeight() const;
	double getBatteryLife() const;
	double getPrice() const;
	int getQuantity() const;
};

