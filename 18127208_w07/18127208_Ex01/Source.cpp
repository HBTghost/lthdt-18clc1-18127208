#include "CItem.h"
#include "CFile.h"
#include "CFolder.h"

void main()
{
	CFolder C("C");
	CFolder System("System");
	CFolder Windows("Windows");
	CFile a_txt("a.txt", 123);
	CFile b_doc("b.doc", 456);
	System.add(&a_txt);
	Windows.add(&b_doc);
	C.add(&System);
	C.add(&Windows);
	std::cout << "Noi dung o dia C ->" << std::endl;
	C.print(0); // print sub-files or folders? 1/0
	CItem* p = C.removeByName("System");
	std::cout << "Noi dung o dia C sau khi xoa thu muc System ->" << std::endl;
	C.print(0);
	p = C.findByName("b.doc");
	if (p != nullptr)
	{
		std::cout << "Tim thay tap tin b.doc trong o dia C" << std::endl;
	}
	else
	{
		std::cout << "Khong tim thay tap tin b.doc trong o dia C" << std::endl;
	}
	p = C.findByName("a.txt");
	if (p != nullptr)
	{
		std::cout << "Tim thay tap tin a.txt trong o dia C" << std::endl;
	}
	else
	{
		std::cout << "Khong tim thay tap tin a.txt trong o dia C" << std::endl;
	}
	p = C.findByName("Windows");
	if (p != nullptr)
	{
		std::cout << "Tim thay thu muc Windows trong o dia C, noi dung thu muc Windows ->" << std::endl;
			p->setHidden(true, true); // set HIDDEN to folder p and all its	items
			p->print(0);
		p->setHidden(false, true); // set UN-HIDDEN to folder p and all	its items
		p->print(0);
	}
	else
	{
		std::cout << "Khong tim thay thu muc Windows trong o dia C" << std::endl;
	}
}