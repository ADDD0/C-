//公共模块，负责定义结构体，初始化，显示结果，回收
//BlockJob.h
#ifndef BLOCKJOB_H_
#define BLOCKJOB_H_
 
#include <vector>
 
const int MINSIZE = 10;		//最小不可分割分区大小
 
							//空闲分区
typedef struct block
{
	int start;	//开始地址
	int size;	//大小
	bool state;	//分区状态 true:空闲 false:占用
}block;
 
//作业
typedef struct job
{
	int size;	//作业大小
	int start;	//分配的分区首址
	int BlockSize;	//分配空闲分区的大小（可能大于作业大小）
};
 
//初始化空闲分区与作业
void init(std::vector<block> &BlockList, std::vector<job> &JobList);
 
//显示结果
void show(std::vector<block> &BlockList, std::vector<job> &JobList);
 
//回收分区
void recycle(std::vector<block> &BlockList, std::vector<job> &JobList);
 

 
//BlockJob.cpp
#include "BlockJob.h"
#include <iostream>
#include <iomanip>
 
//初始化空闲分区与作业
void init(std::vector<block> &BlockList, std::vector<job> &JobList)
{
	std::cout << "输入空闲分区数: ";
	int num;
	std::cin >> num;
 
	std::cout << "输入空闲分区的起始地址与大小: \n";
	block temp;
	for (int i = 0; i < num; ++i)
	{
		std::cin >> temp.start >> temp.size;
		temp.state = true;
		BlockList.push_back(temp);
	}
 
	std::cout << "输入作业数: ";
	std::cin >> num;
	std::cout << "输入作业的大小: \n";
	job tempj;
	for (int i = 0; i < num; ++i)
	{
		std::cin >> tempj.size;
		tempj.BlockSize = 0;
		tempj.start = 0;
		JobList.push_back(tempj);
	}
}
 
//显示结果
void show(std::vector<block> &BlockList, std::vector<job> &JobList)
{
	using std::setw;
	std::cout.setf(std::ios_base::left);
 
	std::cout << "空闲分区表: \n";
	std::cout << setw(10) << "分区号" << setw(10) << "分区大小" << setw(10) << "分区始址" << setw(10) << "状态" << std::endl;
	int num = 0;
	for (std::vector<block>::iterator it = BlockList.begin(); it != BlockList.end(); ++it, ++num)
		std::cout << setw(10) << num << setw(10) << (*it).size << setw(10) << (*it).start << setw(10) << (((*it).state == true) ? "空闲" : "占用") << std::endl;
 
	std::cout << "作业信息: \n";
	std::cout << setw(10) << "作业号" << setw(10) << "作业大小" << setw(10) << "分区大小" << setw(10) << "分区始址" << std::endl;
	num = 0;
	for (std::vector<job>::iterator it = JobList.begin(); it != JobList.end(); ++it, ++num)
		std::cout << setw(10) << num << setw(10) << (*it).size << setw(10) << (*it).BlockSize << setw(10) << (*it).start << std::endl;
}
 
//回收分区
void recycle(std::vector<block> &BlockList, std::vector<job> &JobList)
{
	std::cout << "输入回收分区的首址: ";
	int start;
	std::cin >> start;
 
	for (std::vector<block>::iterator it = BlockList.begin(); it != BlockList.end(); ++it)
	{
		//找到要回收的分区
		if (start == (*it).start)
		{
			//与前一个分区邻接
			if (it != BlockList.begin() && (*(it - 1)).start + (*(it - 1)).size == (*it).start)
			{
				//与后一个分区邻接
				if (it != BlockList.end() - 1 && (*it).start + (*it).size == (*(it + 1)).start)
				{
					//将前一块分区，要回收的分区，后一块分区合并
					(*(it - 1)).size += (*it).size + (*(it + 1)).size;
					(*(it - 1)).state = true;
					BlockList.erase(it);
					BlockList.erase(it);
				}
				else	//不与后一个分区邻接
				{
					//将此分区与前一个分区合并
					(*(it - 1)).size += (*it).size;
					(*(it - 1)).state = true;
					BlockList.erase(it);
				}
			}
			else if(it != BlockList.end()-1 && (*it).start +(*it).size == (*(it+1)).start)	//不与前一个分区邻接，与后一个分区邻接
			{
				//将此分区与后一个分区合并
				(*it).size += (*(it + 1)).size;
				(*it).state = true;
				BlockList.erase(it + 1);
			}
			else	//都不邻接
			{
				(*it).state = true;
			}
			break;
		}
	}
 
	for (std::vector<job>::iterator it = JobList.begin(); it != JobList.end(); ++it)
	{
		if ((*it).start == start)
		{
			(*it).BlockSize = (*it).start = 0;
			break;
		}
	}
}

#endif