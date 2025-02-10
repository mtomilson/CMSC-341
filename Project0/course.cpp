// UMBC - CMSC 341 - Spring 2025 - Proj0
#include "course.h"
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
    cout << "course with " << m_maxNumSections << " created." << endl;
}
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
bool Course::insertSection(int ID, string instructor, int numItems, int numStudents)
{
    // if (m_course == nullptr)
    // {

    //     if (m_maxNumSections == 0)
    //     {
    //         m_course = new Section *[DEFNUMSECTIONS]; // if maxNumSections is not set, set the size of the array to def num sections
    //         m_maxNumSections = DEFNUMSECTIONS;
    //         for (int i = 0; i < m_maxNumSections; i++)
    //         {
    //             m_course[i] = nullptr;
    //         }
    //         cout << "course with def num sections, " << m_maxNumSections << ", created" << endl;
    //     }
    //     else
    //     {

    //         cout << "creating m_course" << endl;
    //         m_course = new Section *[m_maxNumSections]; // creates an array of sections with the size of max num sections
    //         for (int i = 0; i < m_maxNumSections; i++)
    //         {
    //             m_course[i] = nullptr;
    //         }
    //     }
    // }

    if (m_numSections >= m_maxNumSections)
    {
        return false;
    }

    for (int i = 0; i < m_numSections; i++)
    {
        if (m_course[i] != nullptr)
        {
            if (m_course[i]->m_sectionID == ID)
            {
                cout << "Cannot add duplicate id" << endl;
                return false;
            }
        }
    }
    cout << "still running even after return false" << endl;
    if (m_course[m_numSections] != nullptr)
    {
        delete m_course[m_numSections];
    }
    m_course[m_numSections] = new Section(ID, instructor, numItems, numStudents);

    m_numSections++;
    return true;
}
bool Course::insertSection(Section *&aSection)
{

    if ((aSection->m_section == nullptr) ||
        (m_numSections == m_maxNumSections) ||
        (aSection->m_section == nullptr))
    {
        cout << "not adding " << endl;
        return false;
    }

    // check if course is empty, if empty allocate proper memory
    if (m_course == nullptr)
    { // if m_course == nullptr, that means it hasn't been initialized yet
        if (m_maxNumSections == 0)
        {                                             // if maxnumsections = 0, then it hasn't been set i hope
            m_course = new Section *[DEFNUMSECTIONS]; // m_course points to an array of sections
            m_maxNumSections = DEFNUMSECTIONS;
        }
        else
        { // if m_MaxNumSections !== 0, then we use m_MaxNumSections to create m_course
            m_course = new Section *[m_maxNumSections];
        }
    }

    // check dup id

    for (int i = 0; i < m_numSections; i++)
    {
        if ((m_course[i] != nullptr) && (m_course[i]->m_sectionID == aSection->m_sectionID))
        {
            cout << " cannot add, duplicate id" << endl;
            return false;
        }
    }
    if (m_course != nullptr)
    {
        m_course[m_numSections] = aSection;
        m_numSections++;
        return true;
    }

    return false;
}

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
            for (int i = 0; i < m_numSections; i++)
            {
                cout << i;
                m_course[i]->dump();
                cout << m_course[i]->m_sectionID << endl;
                cout << endl;
            }
            return true;
        }
    }
    return false;
}

double Course::courseAverage()
{
    double sectionAverages = 0.0;
    int totalSections = 0;

    cout << "num of sections" << m_numSections << endl;
    for (int i = 0; i < m_numSections; i++)
    {
        sectionAverages += m_course[i]->classAverage();
        totalSections++;
    }
    return sectionAverages / totalSections;
}

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
                    cout << " found section " << endl;
                    return m_course[i];
                }
            }
        }
    }
    return nullptr;
}

Section::Section()
{
    m_sectionID = 1;
    m_numStudents = 0;
    m_numGradingItems = 0;
    m_instructor = "";
    m_section = nullptr;
}
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
Section::~Section()
{
    if (m_section != nullptr)
    {
        for (int i = 0; i < m_numStudents; i++)
        {
            delete[] m_section[i];
        }
        delete[] m_section;
    }

    m_section = nullptr;
    m_instructor = "";
    m_sectionID = 1;
    m_numGradingItems = 0;
    m_numStudents = 0;
}
void Section::clear()
{
    for (int i = 0; i < m_numStudents; i++)
    {
        delete m_section[i];
    }
    delete[] m_section;

    m_instructor = "";
    m_sectionID = 1;
    m_numGradingItems = 0;
    m_numStudents = 0;
}
void Section::simulateData()
{
    Random *random = new Random(0, 100, UNIFORMREAL);
    for (int i = 0; i < m_numStudents; i++)
    {
        for (int j = 0; j < m_numGradingItems; j++)
        {
            m_section[i][j] = random->getRealRandNum();
        }
        cout << endl;
    }

    delete random;
}

double Section::studentAverage(int student)
{

    if (student > m_numStudents || student <= 0)
    {
        cout << "Student Does Not Exist." << endl;
        return 0;
    }
    double totalGrades = 0;

    for (int i = 0; i < m_numStudents; i++)
    {
        if (student - 1 == i)
        {
            for (int j = 0; j < m_numGradingItems; j++)
            {
                cout << "hitting" << endl;
                totalGrades += m_section[i][j];
            }
        }
    }
    return totalGrades / m_numGradingItems;
}
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
int Section::getNumStudents()
{
    return m_numStudents;
}

void Section::displayMemberVariables()
{
    cout << "ID: " << m_sectionID << endl;
    cout << "Number of Students: " << m_numStudents << endl;
    cout << "Number of Grading Items: " << m_numGradingItems << endl;
    cout << "Instructor: " << m_instructor << endl;
    cout << "Section Memory Address: " << m_section << endl;
}
