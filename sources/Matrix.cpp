#include "Matrix.hpp"
using namespace zich;


namespace zich
{

     Matrix::Matrix(vector<double> v, int rows, int cols)
     {

          if ((v.size() != rows * cols) || (rows < 0 || cols < 0))
          {
               throw invalid_argument("Invalid cols and rows cons");
          }
          
          this->_rows = rows;
          this->_cols = cols;
          unsigned int k = 0;
          for (int i = 0; i < rows; i++)
          {
               for (int j = 0; j < cols; j++)
               {
                    this->matMap[i][j] = v[k];
                    k++;
               }
          }
     }
     // A+B
     // A+=B
     Matrix Matrix::operator+(const Matrix &m1)
     {

          if ((_rows != m1._rows) || (_cols != m1._cols))
          {
               throw "Invalid cols and rows +";
          }

          vector<double> _newVec;
          for (int i = 0; i < _rows; i++)
          {
               for (int j = 0; j < _cols; j++)
               {

                    _newVec.push_back(this->matMap[i][j] + m1.matMap.at(i).at(j));
               }
          }

          Matrix new_mat{_newVec, _rows, _cols};

          return new_mat;
     }

     Matrix Matrix::operator-(const Matrix &m1)
     {

          if ((_rows != m1._rows) || (_cols != m1._cols))
          {
               throw "Invalid cols and rows 0";
          }

          vector<double> _newVec;
          for (int i = 0; i < _rows; i++)
          {
               for (int j = 0; j < _cols; j++)
               {

                    _newVec.push_back(this->matMap[i][j] - m1.matMap.at(i).at(j));
               }
          }

          Matrix new_mat{_newVec, _rows, _cols};

          return new_mat;
     }

     Matrix &Matrix::operator+=(const Matrix &m1)
     {
          // throwsre
           if ((_rows != m1._rows) || (_cols != m1._cols))
          {
               throw "Invalid cols and rows +=";
          }
          *this = *this + m1;
          return *this;
     }

     Matrix &Matrix::operator-=(const Matrix &m1)
     {
          // throws
           if ((_rows != m1._rows) || (_cols != m1._cols))
          {
               throw "Invalid cols and rows -=";
          }
          *this = *this - m1;
          return *this;
     }

     Matrix &Matrix::operator++()
     {

          // throws

          for (int i = 0; i < _rows; i++)
          {
               for (int j = 0; j < _cols; j++)
               {

                    this->matMap[i][j]++;
               }
          }

          return *this;
     }
    //  Matrix Matrix::operator++(int)
    //  {

    //       Matrix tempMat = *this;
    //       ++(*this);

    //       return tempMat;
    //  }

     Matrix Matrix::operator--(int){
          
          Matrix tempMat = *this;
          --(*this);
          return tempMat;
     }

     Matrix &Matrix::operator--()
     {

         

          for (int i = 0; i < _rows; i++)
          {
               for (int j = 0; j < _cols; j++)
               {

                    this->matMap[i][j]--;
               }
          }

          return *this;
     }
     Matrix Matrix::operator++(int)
     {
          // throws
          Matrix tempMat = *this;
          ++(*this);
          return tempMat;
     }

     //plus and menos onary


     Matrix Matrix::operator+() // plus unary
     {
         return *this;
     }


     Matrix Matrix::operator-()
     {

          // throws

          vector<double> _newVec;
          for (int i = 0; i < _rows; i++)
          {
               for (int j = 0; j < _cols; j++)
               {

                    _newVec.push_back(matMap[i][j] * -1);
               }
          }

          Matrix new_mat{_newVec, _rows, _cols};
          return new_mat;
     }

     // ******* input/output******
     ostream &operator<<(ostream &output, const Matrix &m)
     {
          // throws
          string str;
          for (int i = 0; i < m._rows; i++)
          {
               str += "[";
               for (int j = 0; j < m._cols; j++)
               {
                    str += to_string(int(m.matMap.at(i).at(j)));
                    if (j != m._cols - 1)
                    {
                         str += " ";
                    }
               }
               str += "]";
               if (i != m._rows - 1)
               {
                    str += "\n";
               }
          }
         return output << str;
         }

     istream &operator>>(std::istream &input, Matrix &m)
     {
           std::string buff;
        int r_counter = 0;
        int c_counter = 0;
        int count = 0;
        std::string Str;
        vector<double> Vec;
        getline(input, buff);
        if (!input)
        {
            std::cout << "fail\n";
        }
        unsigned endOfString = buff.size() - 1;
        for (unsigned i = 0; i < buff.size(); i++)
        {

            if (buff[i] == '[')
            {
                count++;
            }
            if (((i == 0) && (buff[i] != '[')) || ((i == endOfString) && buff[i + 1] != '\0'))
            {
                throw std::invalid_argument("invalid matrix");
            }

            if (buff[i] == ']')
            {
                r_counter++;
                if ((i < buff.size() - 1) && !(buff[i + 1] == ',' && buff[i + 2] == ' '))
                {
                    throw std::invalid_argument("invalid matrix");
                }
            }
            if (isdigit(buff[i]) != 0)
            {
                Str += buff[i];
               
                if ((i < buff.size() - 1) && (isdigit(buff[i + 1]) == 0))
                {
                    int a = stoi(Str);
                    Vec.push_back(a);
                    Str = "";
                    if (count == 1)
                    {
                        c_counter++;
                    }
                }
            }
        }

        Matrix Mat = {Vec,
                          r_counter,
                          c_counter};

        m = Mat;

        return input;
     }

    

//function of kefek matrix *
     Matrix operator*(double num, const Matrix &m1)
     {
          // throws
            
          vector<double> _newVec;
          for (int i = 0; i < m1._rows; i++)
          {
               for (int j = 0; j < m1._cols; j++)
               {

                    _newVec.push_back(num * m1.matMap.at(i).at(j));
               }
          }

          Matrix new_mat{_newVec, m1._rows, m1._cols};
          return new_mat;
     }

     Matrix operator*(const Matrix &m1, double num)
     {
         
          // throws

          return num * m1;
     }

     Matrix &Matrix::operator*=(double num)
     {
          *this = (*this) * num;
          return *this;
     }

     Matrix Matrix::operator*(const Matrix &m1)
     {
           if (_cols != m1._rows)
        {
            throw invalid_argument("matrix is with different size");
        }
        // Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
         vector<double> _newVec;
         for(int  i = 0; i< _rows; i++){
             for(int j =0; j<m1._cols; j++){

            _newVec.push_back(0);
             }
         }
         _newVec.reserve((unsigned long)_rows*(unsigned long)m1._cols);
        Matrix mult{_newVec,_rows,m1._cols};
	for(int i = 0; i < _rows; ++i)
	{
		for(int j = 0; j < m1._cols; ++j)
		{
			for(int k=0; k<_cols; ++k)
			{
				mult.matMap.at(i).at(j) += matMap.at(i).at(k) * m1.matMap.at(k).at(j);
			}
		}
	}
 return mult;
}
	

         
     

     Matrix &Matrix::operator*=(const Matrix &m1)
     {
             if (_cols != m1._rows)
        {
            throw invalid_argument("matrix is with different size");
        }
        // Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
         vector<double> _newVec;
         for(int  i = 0; i< _rows; i++){
             for(int j =0; j<m1._cols; j++){

            _newVec.push_back(0);
             }
         }
        Matrix mult{_newVec,_rows,m1._cols};
	for(int i = 0; i < _rows; ++i)
	{
		for(int j = 0; j < m1._cols; ++j)
		{
			for(int k=0; k<_cols; ++k)
			{
				mult.matMap.at(i).at(j) += matMap.at(i).at(k) * m1.matMap.at(k).at(j);
			}
		}
	}
    matMap=mult.matMap;
    _cols=mult._cols;
       return *this;
     }

     



//boolean og big and smaller than other mattrix
     bool operator>(const Matrix &m1, const Matrix &m2)
     {
          // throws
           if ((m1._rows != m2._rows) || (m1._cols != m2._cols))
          {
               throw "Invalid cols and rows >";
          }

          return (sum_calculator(m1) > sum_calculator(m2));
     }
     bool operator<(const Matrix &m1, const Matrix &m2)
     {
          // throws
           if ((m1._rows != m2._rows) || (m1._cols != m2._cols))
          {
               throw "Invalid cols and rows <";
          }
          return (sum_calculator(m1) < sum_calculator(m2));
     }
     bool operator>=(const Matrix &m1, const Matrix &m2)
     {

          bool ans = (m1 < m2);
          return !ans;
     }
     bool operator<=(const Matrix &m1, const Matrix &m2)
     {
          bool ans = (m1 > m2);
          return !ans;
     }


// == and != for matrix
     bool operator==(const Matrix &m1, const Matrix &m2)
     {
          // m*n  m*n
          // thorws
           if ((m1._rows != m2._rows) || (m1._cols != m2._cols))
          {
               throw "Invalid cols and rowsin equel ma";
          }

          return !(m1 != m2);
     }

     bool operator!=(const Matrix &m1, const Matrix &m2)
     {
          if ((m1._rows != m2._rows) || (m1._cols != m2._cols))
          {
               throw "Invalid cols and rowsin equel ma";
          }
          for (int j = 0; j < m1._rows; j++)
          {
               for (int i = 0; i < m1._cols; i++)
               {
                    if (!(m1.matMap.at(j).at(i) == m2.matMap.at(j).at(i)))
                    {
                         return true;
                    }
               }
          }
          return false;
     }

//function to help me for the sum of numbers

     double sum_calculator(const Matrix &m1)
     {
          int sum = 0;

          for (int i = 0; i < m1._rows; i++)
          {
               for (int j = 0; j < m1._cols; j++)
               {

                    sum += m1.matMap.at(i).at(j);
               }
          }
          return sum;
     }

}
