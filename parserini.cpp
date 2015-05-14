
#include <QtCore/QCoreApplication>
#include <QtCore/QSettings>
#include <QtCore/QString>
#include <QtCore/QDebug>
#include <QtCore/QTextCodec>
#include <QtCore/QVariant>
#include <QtCore/QStringList>

void WriteSettings()
{
	//写
	//Qt中使用QSettings类读写ini文件   
	//QSettings构造函数的第一个参数是ini文件的路径,
	//第二个参数表示针对ini文件,第三个参数可以缺省   
	QSettings *configIniWrite = new QSettings("./conf.ini",QSettings::IniFormat);

	//QSettings("MooseSoft","Clipper");//另外一种构造方式,不会生成ini文件

	//向ini文件中写入内容,setValue函数的两个参数是键值对   
// 	//向ini文件的第一个节写入内容,ip节下的第一个参数   
// 	configIniWrite->setValue("/ip/first", "192.168.0.1");  
// 	//向ini文件的第一个节写入内容,ip节下的第二个参数   
// 	configIniWrite->setValue("ip/second", "127.0.0.1");  
// 	//向ini文件的第二个节写入内容,port节下的第一个参数   
// 	configIniWrite->setValue("port/open", "2222");  
// 	//写入完成后删除指针


	configIniWrite->beginGroup("ip");
	configIniWrite->setValue("first","192.168.0.1");
	configIniWrite->endGroup();

	configIniWrite->beginGroup("port");
	configIniWrite->setValue("open","2222");
	configIniWrite->endGroup();
	
	delete configIniWrite; 
}

void ReadSettings()
{	
	//读
	QSettings *configIniRead = new QSettings("./conf.ini", QSettings::IniFormat);  
	//将读取到的ini文件保存在QString中，先取值，然后通过toString()函数转换成QString类型 

	//QSettings("Moose Soft", "Clipper");//另外一种构造方式,不会生成ini文件

	//循环读取
// 	QStringList keys = configIniRead->allKeys();
// 	for(int i=0; i<keys.size(); i++)
// 	{
// 		qDebug()<<keys[i]<<endl;
// 		QString str = configIniRead->value(keys[i]).toString();
// 		qDebug()<<"str = "<<str<<endl;
// 	}

	//单个读取
//  	QString ipResult = configIniRead->value("/ip/first").toString();  
//  	QString portResult = configIniRead->value("/port/open").toString();  
//  	//打印得到的结果   
//  	qDebug() << ipResult;  
//  	qDebug() << portResult;

	configIniRead->beginGroup("ip");
	QString ipResult = configIniRead->value("first").toString();
	qDebug() << ipResult;
	configIniRead->endGroup();

	configIniRead->beginGroup("port");
	QString portResult = configIniRead->value("open").toString();
	qDebug() << portResult;
	configIniRead->endGroup();

	//读入入完成后删除指针   
	delete configIniRead;
}

int main(int argc, char *argv[])
{

	QCoreApplication a(argc, argv);

	WriteSettings();
	ReadSettings();

	return a.exec();

}


