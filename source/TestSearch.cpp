#include "TestSearch.h"
#include "ISearch.h"
#include "Sequence.h"
#include "Unordered.h"
#include "BestMatch.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <functional>
using namespace std;

TestSearch::TestSearch()
{    
    m_search_type_map["searchSequence"] = new Sequence();
    m_search_type_map["searchUnordered"] = new Unordered();
    m_search_type_map["searchBestMatch"] = new BestMatch();
}

TestSearch::~TestSearch()
{
    //dtor
    map_type::iterator it;
    for ( it = m_search_type_map.begin(); it != m_search_type_map.end(); ++it)
    {
        //cout << "Deleted: " << it->first << endl;
        delete (it->second);
    }
}

void TestSearch::setMatrix(const vector< vector<int> >& iMatrix)
{    
    m_original_matrix = iMatrix;
}

void TestSearch::testSearch(const vector<int>& iSeq, const string& iStrArg)
{
	cout << "====================" << iStrArg << "=====================" << endl;	
    m_search = m_search_type_map[iStrArg];
    m_search->setMatrices(m_original_matrix, iSeq);
    m_search->search();
    cout << "====================" << iStrArg << "=====================" << endl;
}

void TestSearch::benchMark(const vector<int>& iSeq, const string& iStrArg, int iter)
{    
    m_search = m_search_type_map[iStrArg];

    // RNG
    default_random_engine generator;
    // Ginve range for random number
    uniform_int_distribution<int> distribution(1,100);    
    auto rng = bind( distribution, generator );    

    cout << "====================Benchmarking " << iStrArg << "=====================" << endl;
    long int micro_time = 0;
    for ( int t = 0; t < iter; ++t)
    {
        vector< vector<int> > matrix_benchmark;
        for (int i =0; i < 50; ++i)
        {
            vector<int> temp;
            for ( int j =0; j < 50; ++j)
            {
                // Random number = num
                int num = rng();
                //int num = rand() % 1000 + 1;
                temp.push_back(num);                        
            }
            matrix_benchmark.push_back(temp);
        }

        m_search->setMatrices(matrix_benchmark, iSeq);        

        // Initial time
        chrono::steady_clock::time_point start = chrono::steady_clock::now() ;
        
        m_search->search();

        // Final time
        chrono::steady_clock::time_point end = chrono::steady_clock::now() ;

        // 10^-6 seconds(microseconds)
        typedef chrono::duration<int,micro> microsecs_t ;
        microsecs_t duration( chrono::duration_cast<microsecs_t>(end-start) ) ;        
        micro_time += duration.count();
    }

    long int total_avg_time = micro_time/iter;
    cout << "Total avg time = " << total_avg_time << endl;
}