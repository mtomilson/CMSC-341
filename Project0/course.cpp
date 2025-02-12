// UMBC - CMSC 341 - Spring 2025 - Proj0
#include "course.h"

//Default Construtor 
Course::Course()
{
    m_numSections = 0;
    m_course = new Section *[DEFNUMSECTIONS];
    for (int i = 0; i < DEFNUMSECTIONS; i++)
    {
        m_course[i] = nullptr;
    }
    m_maxNumSections = 0;
}

//Overloaded Constructor
//@param maxNumSections - takes in max num sections 
Course::Course(int maxNumSections)
{
    m_maxNumSections = maxNumSections;
    // m_course = new Section *[maxNumSections];

    m_course = new Section *[maxNumSections];
    for (int i = 0; i < maxNumSections; i++)
    {
        m_course[i] = nullptr;
    }
    m_numSections = 0;
}

//Destructor

Course::~Course()
{
    if (m_course != nullptr)
    {
        for (int i = 0; i < m_numSections; i++)
        {
            delete m_course[i];
        }
    }

    delete[] m_course;
    m_course = nullptr;
    m_maxNumSections = 0;
    m_numSections = 0;
}


 /**

insertSection() method will insert a section into the course object
@param ID - id for the section
@param instructor - name of instructor for the section
@param numItems - number of grading items
@param numStudents - number of students for the section
@return bool - returns true or false if the section was added or not

 */

bool Course::insertSection(int ID, string instructor, int numItems, int numStudents)
{

    if (m_numSections >= m_maxNumSections || numStudents == 0 || numItems == 0) // cannot add if number of students or grading items is 0
    {
        return false;
    }

    for (int i = 0; i < m_numSections; i++)
    {
        if (m_course[i] != nullptr)
        {
            if (m_course[i]->m_sectionID == ID)
            {
                return false;
            }
        }
    }
    if (m_course[m_numSections] != nullptr)
    {
        delete m_course[m_numSections];
    }
    m_course[m_numSections] = new Section(ID, instructor, numItems, numStudents);

    m_numSections++;
    return true;
}

/*

insertSection() method will insert a section into the course object 
@param aSection - pointer to a reference of a section 
@return bool - returns true or false if the section was added or not 

*/


bool Course::insertSection(Section *&aSection)
{
    bool canAdd = true;
    if ((aSection->m_section == nullptr) ||
        (m_numSections == m_maxNumSections) ||
        (aSection->m_numGradingItems == 0) || aSection->m_numStudents == 0 || aSection == nullptr)
    {
        canAdd = false;
    }
    // check dup id

    for (int i = 0; i < m_numSections; i++)
    {
        if ((m_course[i] != nullptr) && (m_course[i]->m_sectionID == aSection->m_sectionID))
        {
            canAdd = false;
        }
    }

    if (canAdd)
    {
        m_course[m_numSections] = aSection;
        m_numSections++;
    }
    else {
        delete aSection;
    }

    return canAdd;
}

/*
removeSection() method will remove sections from the course
@param sectionID - passes in sectionID to be removed
@return bool - returns true or false if it was removed or not

*/


bool Course::removeSection(int sectionID)
{
    int deletedIndex = 0;
    // find the corresponding sectoin with the sectionID
    for (int i = 0; i < m_numSections; i++)
    {
        if ((m_course[i]->m_sectionID == sectionID) && m_course[i] != nullptr)
        {
            deletedIndex = i;
            delete m_course[i];
            m_course[i] = nullptr;

            for (int i = deletedIndex; i < m_numSections - 1; i++)
            {
                m_course[i] = m_course[i + 1];
            }
            m_course[m_numSections - 1] = nullptr;
            m_numSections--;
            return true;
        }
    }
    return false;
}

/*

courseAverage() method will calculate the average of course 
return double - returns the calculated course average 

*/


double Course::courseAverage()
{
    double totalGrades = 0.0;
    int numberOfItems = 0;
    if (m_numSections == 0)
    { // if there's no sections in the course then we return 0.0
        return 0.0;
    }

    for (int i = 0; i < m_numSections; i++)
    {
        for (int j = 0; j < m_course[i]->m_numStudents; j++)
        {
            for (int k = 0; k < m_course[i]->m_numGradingItems; k++)
            {
                totalGrades += m_course[i]->m_section[j][k];
                numberOfItems++;
            }
        }
    }

    return totalGrades / numberOfItems;
}

/*

displaySections() displays the sections inside the course

 */

void Course::displaySections()
{
    for (int i = 0; i < m_numSections; i++)
    {
        cout << i;
        m_course[i]->dump();
        cout << m_course[i]->m_sectionID << endl;

        cout << endl;
    }
}

/*

getSection() will return the section with the correspodning section id 
@param sectionID - passes in the section id of the section we want
@return Section* - returns the section with the corresponding id 

*/

Section *Course::getSection(int sectionID) const
{
    if (m_course != nullptr)
    {
        for (int i = 0; i < m_numSections; i++)
        {
            if (m_course[i] != nullptr)
            {
                if (m_course[i]->m_sectionID == sectionID)
                {
                    return m_course[i];
                }
            }
        }
    }
    return nullptr;
}

//Default Constructor

Section::Section()
{
    m_sectionID = 1;
    m_numStudents = 0;
    m_numGradingItems = 0;
    m_instructor = "";
    m_section = nullptr;
}

/*

Overloaded Constructor
@param ID - passes in section ID
@param instructor - passes in the instructor name
@param items - passes in the amount of grading items
@param students - passes in the amount of students

 */

Section::Section(int ID, string instructor, int items, int students)
{
    // checks if the num grading items or students is negative, if negative create empty object.
    if (items < 0 || students < 0)
    {
        m_sectionID = 1;
        m_instructor = "";
        m_numGradingItems = 0;
        m_numStudents = 0;
        m_section = nullptr;
    }
    else
    {
        m_sectionID = ID;
        m_instructor = instructor;
        m_numGradingItems = items;
        m_numStudents = students;
        m_section = new double *[students];
        for (int i = 0; i < students; i++)
        {
            m_section[i] = new double[items];
        }
    }
}

//Default constructor

Section::~Section()
{
    clear();
}

//clear() method will clear and deallocate any memory 

void Section::clear()
{
    for (int i = 0; i < m_numStudents; i++)
    {
        delete[] m_section[i];
    }
    delete[] m_section;

    m_instructor = "";
    m_sectionID = 1;
    m_numGradingItems = 0;
    m_numStudents = 0;
}

//simulateData() method will fill the section's 2D array with data

void Section::simulateData()
{
    Random random(0, 100, UNIFORMREAL);
    for (int i = 0; i < m_numStudents; i++)
    {
        for (int j = 0; j < m_numGradingItems; j++)
        {
            m_section[i][j] = random.getRealRandNum();
        }
    }
}

/*

studentAverage() will calculate the average grades of a given student
@param student - studnet number to calculate the average for 
@return double - returns the calculated student average of the given student

*/

double Section::studentAverage(int student)
{
    bool found = false;

    if (student > m_numStudents || student < 0)
    {
        cout << "Student Does Not Exist." << endl;
        return 0;
    }
    double totalGrades = 0;

    for (int i = 0; i < m_numStudents; i++)
    {
        if (student == i)
        {
            for (int j = 0; j < m_numGradingItems; j++)
            {
                found = true;
                totalGrades += m_section[i][j];
            }
        }
    }
    if (found == false)
    {
        return 0.0;
    }
    else
    {
        return totalGrades / m_numGradingItems;
    }
}

/*

testAverage() method will calculate the average score of a test
@param test - test to calculate 
@return double - returns the calculated average 

 */


double Section::testAverage(int test)
{
    double totalGrades = 0;

    if (test >= m_numGradingItems)
    {
        return 0;
    }

    for (int i = 0; i < m_numGradingItems; i++)
    {
        if (i == test)
        {
            for (int j = 0; j < m_numStudents; j++)
            {
                totalGrades += m_section[j][i];
            }
        }
    }
    return totalGrades / m_numStudents;
}

/*

classAverage() method will return the average score of all students and all of their tests 
@return double - returns the calculated average of the class

*/

double Section::classAverage()
{
    double totalGrades = 0;
    int totalItems = 0;
    for (int i = 0; i < m_numStudents; i++)
    {
        for (int j = 0; j < m_numGradingItems; j++)
        {
            totalItems++;
            totalGrades += m_section[i][j];
        }
    }

    return totalGrades / totalItems;
}

/*

Copy Constructor
@param rhs - Section object to copy data from 

*/

Section::Section(const Section &rhs)
{
    m_sectionID = rhs.m_sectionID;
    m_instructor = rhs.m_instructor;
    m_numGradingItems = rhs.m_numGradingItems;
    m_numStudents = rhs.m_numStudents;
    m_section = new double *[m_numStudents];

    for (int i = 0; i < m_numStudents; i++)
    {
        m_section[i] = new double[m_numGradingItems];
    }

    for (int i = 0; i < m_numStudents; i++)
    {
        for (int j = 0; j < m_numGradingItems; j++)
        {
            m_section[i][j] = rhs.m_section[i][j];
        }
    }
}

/*

Assign Operator will copy the right hand side of the = sign 
@param rhs - object to copy 
@return Section& - returns the copied section 

*/


const Section &Section::operator=(const Section &rhs)
{
    if (this != &rhs)
    { // deallocate memory
        for (int i = 0; i < m_numStudents; i++)
        {
            delete[] m_section[i];
        }
        delete[] m_section;
    }

    m_sectionID = rhs.m_sectionID;
    m_instructor = rhs.m_instructor;
    m_numGradingItems = rhs.m_numGradingItems;
    m_numStudents = rhs.m_numStudents;

    if (m_numGradingItems > 0 && m_numStudents > 0)
    {
        m_section = new double *[m_numStudents];
        for (int i = 0; i < m_numStudents; i++)
        {
            m_section[i] = new double[m_numGradingItems];
            for (int j = 0; j < m_numGradingItems; j++)
            {
                m_section[i][j] = rhs.m_section[i][j];
            }
        }
    }
    else
    {
        m_section = nullptr;
    }

    return *this;
}

//dumps data 

void Section::dump()
{
    if (m_numGradingItems > 0 && m_numStudents > 0 && m_section != nullptr)
    {

        cout << setw(8) << "        ";
        for (int a = 1; a <= m_numGradingItems; a++)
            cout << setw(8) << "Test" << a;
        cout << endl;
        for (int i = 1; i <= m_numStudents; i++)
        {
            cout << setw(8) << "Student" << i << " ";
            for (int j = 1; j <= m_numGradingItems; j++)
            {
                cout << setw(8) << m_section[i - 1][j - 1] << " ";
            }
            cout << endl;
        }
    }
}

// additional getters
/*

getNumStudents() returns the number of students
@return int - returns the number of students

*/
int Section::getNumStudents()
{
    return m_numStudents;
}

/*

displayMemberVariables() displays the member variables of section

*/

void Section::displayMemberVariables()
{
    cout << "ID: " << m_sectionID << endl;
    cout << "Number of Students: " << m_numStudents << endl;
    cout << "Number of Grading Items: " << m_numGradingItems << endl;
    cout << "Instructor: " << m_instructor << endl;
    cout << "Section Memory Address: " << m_section << endl;
}
