/* This is a grade calculator for my programming class. It reads in a list of grades
as input and classifies
them by category. Homework is weighted at 40% of the final letter grade,
Labwork accounts for 10% of the final
letter grade, Zybooks accounts for 5% of the final grade, class engagement accounts for 5% also, Exams
account for the remaining 40%. The homework, reading, engagement, and labworks are running averages,
The reading and engagement averages have 15% added on at the end of the semester, up to 100%, The Exam
final weighted grade is the maximum of the final, or the average of exam 1,2, and the final. Labs are
graded as 1 or 0 (incomplete or complete) */

/* grades are read in as whole floating point numbers, not decimals. For instance Exam = 75.2
not .752 */


// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>


using std::cin, std::cout, std::endl;
using std::string, std::getline;

// function declarations before main, definitions are listed after

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

//print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);


// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();



   //declaring needed variables:

   //exam variables needed:
    double exam_score_total = 0.0; //to hold sum of exams while in loop
    int number_of_exams = 0; //keeps track of total number of exams for averaging

    // Variable needed to hold the final:
    double final_exam_score = 0.0; //there is only one grade here, so we dont need to average it

    //variables for homeworks:
    double homework_score_total = 0.0; //holds the running total for homeworks in loop
    int number_of_homework_scores = 0; //holds number of homeworks for average

    //lab variables, these are graded as 100 or 0 only
    double total_lw_score = 0.0;
    int number_of_lw = 0;

    //zybooks reading variables:

    double total_read_score = 0.0;
    int num_reading_scores = 0;

    //engagement score variables, this is akin to a participation grade

    double total_engage_score = 0.0;
    int num_engage_scores = 0;


     string line;
    // read one line from standard input
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) { //begin processing loop
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            exam_score_total = exam_score_total + score; //sums up exam num_engage_scores
            number_of_exams++; //keeps track of total exams entered
            } //end first if block
        else if (category == "final-exam") {
            final_exam_score += score; //stores final score in this variable
            number_of_exams++; //increments exams for computing total average out of exams and final
        } else if (category == "hw") {
            homework_score_total = score + homework_score_total; //keeps track of total hw grade
            number_of_homework_scores++; //tracks number of hw entries throughout loop
        } else if (category == "lw") {
            if( (score - 1.0) < 0.01 ){ //== comparison not good for doubles
               total_lw_score = total_lw_score + 100; //give 100 to total score for each complete lw
               number_of_lw++; //tracks lw
             }
            else{
                total_lw_score = total_lw_score + 0; //adds 0 for each incomplete
                number_of_lw++;
            } //end nested if-else block
        } else if (category == "reading") {
            total_read_score = total_read_score + score; //tracks total read score
            num_reading_scores++; //tracks num reading entries
        } else if (category == "engagement") {
            total_engage_score = total_engage_score + score;
            num_engage_scores++;
        } else {
            cout << "ignored invalid input" << endl;
        } //end if else if block

        // get the next line from standard input
        getline(cin, line);
    } //end file processing loop


    /* averages are computed as total divided by the number of entries
    if a student has no entries for some category, then
    we will have a divide by zero error. So each tracking
    variable that keeps up with the number of entries, must be
    set to not equal 0. */

    if(num_engage_scores == 0){
        num_engage_scores++; //sets it equal to 1, dividing by 1 will not change the value
    }
    if(num_reading_scores == 0){
        num_reading_scores++;
    }
    if(number_of_exams == 0){
        number_of_exams++;
    }
    if(number_of_lw == 0){
        number_of_lw++;
    }
    if(number_of_homework_scores == 0){
        number_of_homework_scores++;
    }

    //computing averages for each category

    double exam_average = 0.0;
    double hw_average = 0.0;
    double lw_average = 0.0;
    double reading = 0.0;
    double engagement = 0.0;
    //exam_av = (the total exam 1, 2 sum + final) / 3 tests
    //reading and engage have 15% added on up to 100
    exam_average = (exam_score_total + final_exam_score) / 3; //always 3
    hw_average = homework_score_total / number_of_homework_scores;
    lw_average = total_lw_score / number_of_lw;
    reading = (total_read_score / num_reading_scores) + 15.0;
    engagement = (total_engage_score / num_engage_scores) + 15.0;

    //method commented out was used to add the 15% to engage and read
    //it was dropped for more efficient method

    //reading and engagement have 15 points added on to them up to 100
    //if statements to append needed points on to two categories:
  /*  if(reading <= 85){
        reading += 15; //will add 15 points to any score less than or equal to 85
    }
    if(reading > 85 && reading < 100){
        double point_tracker = 0;
        point_tracker = 100 - reading; //find points that will make the score 100
        reading = reading + point_tracker; //appends them to score to make it 100
    }
    if(reading >= 100){ //in case of some error where reading is greater than 100
        reading = 100;
    }
    //repeat for engagement
    if(engagement <= 85){
        engagement += 15;
    }
    if(engagement > 85 && engagement < 100){
        double point_tracker2 = 0;
        point_tracker2 = 100 - engagement;
        engagement = engagement + point_tracker2;
    }
    if(engagement >= 100){
        engagement = 100;
    } //end if statements to add up to 15 points to two categories */

    if(engagement > 100.0){
      enagement = 100.0; //sets engage to 100% if adding 15 caused it to go above that
    }
    if(reading > 100.0) {
      reading = 100.0;

    }

    /*if the final is greater than the total exam average then it is used in the computation
    of the final grade */

    //sets exam average to correct value
    if(exam_average < final_exam_score){
        exam_average = final_exam_score;
    }

    //compute the weighted total:
    double exam_points = 0.4 * exam_average;
    double lw_points = 0.1 * lw_average;
    double hw_points = 0.4 * hw_average;
    double reading_points = 0.05 * reading;
    double engagement_points = 0.05 * engagement;


    double weighted_total = 0;  //holds weighted total grade:

    weighted_total = exam_points + hw_points + lw_points + reading_points + engagement_points;


    char final_letter_grade = 'X'; //holds letter grade

   //grades classified as A-B-C-D-F in certain ranges of points earned
    if(weighted_total >= 90){ //if total points is greater than 90 user gets an A
        final_letter_grade = 'A';
    }
    if(weighted_total >= 80 && weighted_total < 90){
         final_letter_grade = 'B'; //if total points is in between 80 - 89.9 user gets B
     }
    if(weighted_total >= 70 && weighted_total < 80){
         final_letter_grade = 'C';
     }

    if(weighted_total >= 60 && weighted_total < 70){
        final_letter_grade = 'D';
    }
    if(weighted_total < 60){
        final_letter_grade = 'F';
    }

    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);

 return 0;
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
