<?php

require_once('tcpdf/config/lang/eng.php');
require_once('tcpdf/tcpdf.php');



// Extend the TCPDF class to create custom Header and Footer
class MYPDF extends TCPDF {
	
	 var $module_code;
	
    //Page header
    public function set_module_code($modulecode)
    {
    	   $this->module_code = $modulecode;
    	  
    }
    
    public function Header() {
        // Logo
        $this->Image(K_PATH_IMAGES.'logo.jpg', 10, 8, 35);
        // Set font
        $this->SetFont('helvetica', 'B', 20);
        // Move to the right
        $this->Cell(80);
        // Title
        $title = 'Attendance List-'.$this->module_code;
        $this->Cell(30, 10, $title, 0, 0, 'C');
        // Line break
        $this->Ln(20);
    }
    
    // Page footer
    public function Footer() {
        // Position at 1.5 cm from bottom
        $this->SetY(-15);
        // Set font
        $this->SetFont('helvetica', 'I', 8);
        // Page number
        $this->Cell(0, 10, 'Page '.$this->getAliasNumPage().'/'.$this->getAliasNbPages(), 0, 0, 'C');
    }
}












$pdf = new MYPDF(PDF_PAGE_ORIENTATION, PDF_UNIT, PDF_PAGE_FORMAT, true, 'UTF-8', false); 

$pdf->set_module_code($module_code);
// set default header data
//$pdf->SetHeaderData(PDF_HEADER_LOGO, PDF_HEADER_LOGO_WIDTH, PDF_HEADER_TITLE, PDF_HEADER_STRING);

// set header and footer fonts
$pdf->setHeaderFont(Array(PDF_FONT_NAME_MAIN, '', PDF_FONT_SIZE_MAIN));
$pdf->setFooterFont(Array(PDF_FONT_NAME_DATA, '', PDF_FONT_SIZE_DATA));

//set margins
$pdf->SetMargins(PDF_MARGIN_LEFT, PDF_MARGIN_TOP, PDF_MARGIN_RIGHT);
$pdf->SetHeaderMargin(PDF_MARGIN_HEADER);
$pdf->SetFooterMargin(PDF_MARGIN_FOOTER);

//set auto page breaks
$pdf->SetAutoPageBreak(TRUE, PDF_MARGIN_BOTTOM);

//set image scale factor
$pdf->setImageScale(PDF_IMAGE_SCALE_RATIO); 

//set some language-dependent strings
$pdf->setLanguageArray($l); 

// ---------------------------------------------------------

// set font
$pdf->SetFont('times', '', 12);

// add a page
$pdf->AddPage();



$students = students_taken($module_code);



$html = '

<table border="1">
<tr>
<th>No.</th>
<th>Name</th>
<th>Student ID</th>
<th>Signature</th>
</tr>';
$i=1;
foreach($students as $stu)
{
$html.='
<tr>
<td>'.$i.'</td>
<td>'.strtoupper(get_name($stu,'student')).'</td>
<td>'.get_rollno($stu).'</td>
<td>             </td>
</tr>'

;
$i++;
}

$html.='
</table>
   
  ';

$pdf->writeHtml($html);



// print a line using Cell()
//$pdf->Cell(0, 12, 'Example 001 - €אטילעש', 1, 1, 'C');

// ---------------------------------------------------------

//Close and output PDF document
$pdf->Output('attendance_list_'.$module_code.'.pdf', 'I');


?>