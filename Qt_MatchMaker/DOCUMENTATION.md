MatchMaker
==========

The purpose of the MatchMaker application is to input user information from a database, perform matching operations on that data, and then export the matches to a PDF. Here you will find a brief summary of how these three tasks are accomplished along with any other relevant information, such as how they may be improved or extended. For more information about individual processes or implementation, please see the respective source files.

1. __Input__
     * In this step, the application will access a database and store user information, such as name, gender, grade, and survey answers. All of this is done through the QtSql module, which means the program has the potential to support any database that the module supports. While it is not necessarily straightforward, in order to add support for another database type, the following must be created:
	     * An addition to the DatabaseType enum located in Database.h
		 * A subclass of the Database interface also located in Database.h
		 * A subclass of StepWidget that will allow the user to input information required to connect to the database
		 * An addition to the database type combo box located in DbChooseWidget
		 * An addition to the the DatabaseDialog::State enum, which is used to track the current StepWidget that DatabaseDialog displays
		 * The restructure of various if else statements in DatabaseDialog that allows the dialog to advanced and go back to other StepWidgets
		 * And finally, the addition of an overload of the signal/slotAddConnect(...) functions in the class DatabaseManager
	 Seeing as the addition of other database types is not a streamlined process, the creation of a better database connection system may be a possible future addition. However, for a project that only requires SQLite and MySQL database connections, it will suffice.
2. __Matching__
     * The entire application is centred around the matchmaking process. In order to calculate the relative possibility for two users to be matched, their survey answers are used to find the "distance" between the users. In this model, the each answer is treated as an element in a multidimensional coordinate system, and the linear algebra concept of vector length is applied to find the length of the vector between the two points. In this case, the vector will be in *R*^(q + 1) space, where q is the number of questions. The number of dimensions is q + 1 because the grade level is also considered an answer.
	 Finding the distance between two vectors in one thing, but how are the match percentages between two users calculated? This is where the Answer Range field in the input section comes into play. If the maximum range of the answers is known, then we can find the maximum distance that any two vectors can ever be from one another. Thus, the match percentages are just the distance between two vectors divided by the maximum distance possible. To see the exact implementation of this process, please refer to MatchEngine::getMatchLikelihood(...) in MatchEngine.cpp.
3. __Output__
     * After the users have been matched, the results need to be printed. Each page is rendered by PrintEngine using a QPainter, and then the combined documents are saved as a PDF file. A future addition to the application might want to add support to print the matches directly to a printer, however, as of now, a PDF is a much better alternative because the results are saved on file and a variety of complex page layouts can be printed using various PDF viewing applications.
