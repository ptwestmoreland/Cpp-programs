// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
//#include <cmath>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want

    // all variables are used to keep sum of categories as score read in from file or keep track of how many are read in
    double examGradeSum = 0.0;
    unsigned int numExams = 0;
    double homeworkScores = 0.0;
    unsigned int numHwScores = 0;
    double readingScores = 0.0;
    unsigned int numReadingScores = 0;
    double finalExamScore = 0.0; // one score for this category
    double engagementScores = 0.0;
    unsigned int numEngagementScores = 0;
    double labScores = 0.0; // read in as 1.0 or 0
    unsigned int numLwScores = 0;
    unsigned int readCount = 0;
    unsigned int finalCtr = 0;



    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            examGradeSum += score; // take running sum of exam grades
            numExams++; // increment number of exams

        } else if (category == "final-exam") {
            finalExamScore = score; // store exam grade
            finalCtr++; // increment for computing average

        } else if (category == "hw") {
            homeworkScores += score;
            numHwScores += 1;
        } else if (category == "lw") {

            //numLabScores += 1;
            if(abs((score - 1.0)) <= 0.01){ // comparing double for equality
              labScores += 100.0;
              numLwScores += 1;
            }
            else{
              labScores += 0.0;
              numLwScores += 1;
            }
        } else if (category == "reading") {
            readingScores += score;
            numReadingScores += 1;
            readCount++;
        } else if (category == "engagement") {
            engagementScores += score;
            numEngagementScores += 1;
        }else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // TODO(student): compute component averages

    double exam_average = 0;
    double hw_average = 0;
    double lw_average = 0;
    double reading = 0;
    double engagement = 0;
  // protect against divide by zero errors
    if(numHwScores == 0){
      numHwScores = 1;
    }
    if(numLwScores == 0){
      numLwScores = 1;
    }
    if(numReadingScores == 0){
      numReadingScores = 1;
    }
    int a = 0;
    if(numEngagementScores == 0){
      numEngagementScores = 1;
      a = 5;
    }
    if(numExams == 0){
      numExams = 1;
    }
    if(finalCtr == 0){
      finalCtr = 1;
    }

    if(finalCtr == 1 && numExams == 1){
      exam_average = (examGradeSum + finalExamScore) / 2.0;

    }
    else if(finalCtr == 0 && numExams == 1){
      exam_average = examGradeSum / 2.0;
    }
    else{
      exam_average = (examGradeSum + finalExamScore) / 3.0;
    }

  //  exam_average = (examGradeSum / numExams) + (finalExamScore / finalCtr);


    if(finalExamScore > exam_average){
      exam_average = finalExamScore;
    }
    hw_average = homeworkScores / numHwScores;
    lw_average = labScores / numLwScores;
    reading = (readingScores / numReadingScores);
    engagement = (engagementScores / numEngagementScores);

    // syllabus states to add 15% up to 100 on these reading and engagement if there is an grade

    if(readCount > 0){
      reading += 15.0; // if no reading entries processed numReadingScores == 1 right now
    }
    if(numEngagementScores >= 1 && a == 0){
      engagement += 15.0;
    }

    if(reading > 100.0){
      reading = 100.0;
    }
    if(engagement > 100.0){
      engagement = 100.0;
    }



    // TODO(student): compute weighted total of components
    double weighted_total = (0.4 * exam_average) + (0.4 * hw_average) + (0.1 * lw_average) + (0.05 * reading) + (0.05 * engagement);

    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';
    if(weighted_total < 60.0){
      final_letter_grade = 'F';
    }
    else if((weighted_total >= 60.0) && (weighted_total < 70.0)){
      final_letter_grade = 'D';
    }
    else if((weighted_total >= 70.0) && (weighted_total < 80.0)){
      final_letter_grade = 'C';
    }
    else if((weighted_total >= 80.0) && (weighted_total < 90.0)){
      final_letter_grade = 'B';
    }
    else{
      final_letter_grade = 'A';
    }

    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);
}


void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}
