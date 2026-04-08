#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	// Mohamed hany added the following if condition which checks that the passed "v"
	// is in the range of the grid vertical cells (from 0 to NumVerticalCells - 1).
	if (v >= 0 && v < NumVerticalCells) 
	{
		vCell = v; 
		return true;
	}
	else {
		return false; // This means that it couldn't add a new vertical cell.
	}
}

bool CellPosition::SetHCell(int h) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	// Mohamed Hany added the following if condition for the same purpose as in SetVCell().
	if (h >= 0 && h < NumHorizontalCells)
	{
		hCell = h;
		return true;
	}
	else {
		return false; // This means that it couldn't add a new Horizontal cell.
	}
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file
	//Mohamed Hany added the following if condition which checks that both data members (vCells and hCells)
	// are in the range of the grid.
	if (vCell >= 0 && vCell < NumVerticalCells && hCell >= 0 && hCell < NumHorizontalCells) {
		return true; // This means that the cell is valid.
	}
	else {
		return false;
	} 
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file 
	// Mohamed hany added this code:
	// This function takes a pointer with data type CellPosition and calculates the cell Number
	// using the data members of the passed cellPosition (vCell and hCell) and calculates the cell number.
	int cellNumber;

	int verticalCell = cellPosition.VCell();
	int horizontalCell = cellPosition.HCell();
	if (verticalCell == 0)
	{
		cellNumber = 45 + horizontalCell;
	}
	else if (verticalCell == 1) {
		cellNumber = 34 + horizontalCell;

	}
	else if (verticalCell == 2) {
		cellNumber = 23 + horizontalCell;
	}
	else if (verticalCell == 3) {
		cellNumber = 12 + horizontalCell;
	}
	else if (verticalCell == 4) {
		cellNumber = 1 + horizontalCell;
	}

	return cellNumber; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// This function needs to be implemented
	CellPosition position;
	if (cellNum > 44) {
		position.SetVCell(0);
		position.SetHCell(cellNum - 45);
	}
	else if(cellNum > 33 && cellNum < 45){
		position.SetVCell(1);
		position.SetHCell(cellNum - 34);
	}
	else if (cellNum > 22 && cellNum < 34) {
		position.SetVCell(2);
		position.SetHCell(cellNum - 23);
	}
	else if (cellNum > 11 && cellNum < 23) {
		position.SetVCell(3);
		position.SetHCell(cellNum - 12);
	}
	else {
		position.SetVCell(4);
		position.SetHCell(cellNum - 1);
	}
	/// TODO: Implement this function as described in the .h file

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum(int addedNum, Direction direction)
{ // 2 

	/*
	switch (direction) {
	case UP:
	{

	}
	}
	*/

	if (direction==UP)
	{
		for (int i = 0; i < addedNum; i++)
		{
			while (vCell != 0)
			{
				vCell -= 1;
			}
		}

	}
	else if (direction == DOWN)
	{
		for (int i = 0; i < addedNum; i++)
		{
			while (vCell != 4)
			{
				vCell += 1;
			}
		}
	}
	else if (direction == RIGHT)
	{
		for (int i = 0; i < addedNum; i++)
		{
			while (hCell != 11)
			{
				hCell += 1;
			}
		}
	}
	else if (direction == LEFT )
	{
		for (int i = 0; i < addedNum; i++)
		{
			while (hCell != 0)
			{
				hCell -= 1;
			}
		}
	}


	/// TODO: Implement this function as described in the .h file
	//mohamed hossameldin

	// Note: this function updates the data members (vCell and hCell) of the calling object

}