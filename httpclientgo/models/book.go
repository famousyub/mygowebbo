package models 
import "gorm.io/gorm"


type Book struct{
	gorm.Model
	ID     uint   `json:"id" gorm:"primary_key"`
  Title  string `json:"title"`
  Author string `json:"author"`


}


//create a user
func CreateUser(db *gorm.DB, User *Book) (err error) {
	err = db.Create(User).Error
	if err != nil {
		return err
	}
	return nil
}

//get users
func GetUsers(db *gorm.DB, Book *[]Book) (err error) {
	err = db.Find(Book).Error
	if err != nil {
		return err
	}
	return nil
}

//get user by id
func GetUser(db *gorm.DB, User *Book, id int) (err error) {
	err = db.Where("id = ?", id).First(User).Error
	if err != nil {
		return err
	}
	return nil
}

//update user
func UpdateUser(db *gorm.DB, User *Book) (err error) {
	db.Save(User)
	return nil
}

//delete user
func DeleteUser(db *gorm.DB, User *Book, id int) (err error) {
	db.Where("id = ?", id).Delete(User)
	return nil
}