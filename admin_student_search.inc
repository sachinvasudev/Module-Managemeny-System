
<!--Task Navigation-->
<hr/>
<h1 class="sideh1">Search Student</h1>
<br>
<p align="left"><font size="+1">
<form method="POST" action="admin_home.php">
Student Name: <input type="text" name="name" value="" size="15"><br><br>
Student ID: <input type="text" name="stu_id" value="" size="15"><br><br>
Course Code: <select size="1" name="c_code"><option>G400</option><option>G500</option><option>G647</option></select><br><br>
Year : <select size="1" name="year"><option>Foundation</option><option>First</option><option>Second</option><option>Third</option></select><br><br>
MEF: <select size="1" name="D2"><option>Summitted</option><option>Not Summitted</option></select>
<br></font></p>
<p class="paraleft"><input name="Search" type="submit" value="Search"></p>
<input type="hidden" name="task" value="student">
<input type="hidden" name="do_search" value=" ">

</form>
<form method="POST" action="admin_home.php">
<p class="paraleft"><input name="Cancel" type="submit" value="Cancel"></p>
<input type="hidden" name="task" value="student">

</form>

</div>
<!--end Task Detail -->
</div>
</body>
</html>