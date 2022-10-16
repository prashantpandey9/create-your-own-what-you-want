import React, { useState, Fragment } from "react";
import { nanoid } from "nanoid";
import "./App.css";
import data from "./mock-data.json";
import ReadOnlyRow from "./components/ReadOnlyRow";
import EditableRow from "./components/EditableRow";

const App = () => {
  const [contacts, setContacts,reset] = useState(data);
  const [addFormData, setAddFormData,] = useState({
    fullName: "",
    address: "",
    age: "",
    phoneNumber: "",
    email: "",
    occupation: "",
    feedback: "",
  });

  const [editFormData, setEditFormData] = useState({
    fullName: "",
    address: "",
    age: "",
    phoneNumber: "",
    email: "",
    occupation: "",
    feedback: "",
  });

  const [editContactId, setEditContactId] = useState(null);

  const handleAddFormChange = (event) => {
    event.preventDefault();

    const fieldName = event.target.getAttribute("name");
    const fieldValue = event.target.value;

    const newFormData = { ...addFormData };
    newFormData[fieldName] = fieldValue;

    setAddFormData(newFormData);
  };

  const handleEditFormChange = (event) => {
    event.preventDefault();

    const fieldName = event.target.getAttribute("name");
    const fieldValue = event.target.value;

    const newFormData = { ...editFormData };
    newFormData[fieldName] = fieldValue;

    setEditFormData(newFormData);
  };

  const handleAddFormSubmit = (event) => {
    event.preventDefault();

    const newContact = {
      id: nanoid(),
      fullName: addFormData.fullName,
      address: addFormData.address,
      age: addFormData.age,
      phoneNumber: addFormData.phoneNumber,
      email: addFormData.email,
      occupation: addFormData.occupation,
      feedback: addFormData.feedback,
    };

    const newContacts = [...contacts, newContact];
    setContacts(newContacts);
  };

  const handleEditFormSubmit = (event) => {
    event.preventDefault();

    const editedContact = {
      id: editContactId,
      fullName: editFormData.fullName,
      address: editFormData.address,
      age: editFormData.age,
      phoneNumber: editFormData.phoneNumber,
      email: editFormData.email,
      occupation: editFormData.occupation,
      feedback: editFormData.feedback,
    };

    const newContacts = [...contacts];

    const index = contacts.findIndex((contact) => contact.id === editContactId);

    newContacts[index] = editedContact;

    setContacts(newContacts);
    setEditContactId(null);
  };

  const handleEditClick = (event, contact) => {
    event.preventDefault();
    setEditContactId(contact.id);

    const formValues = {
      fullName: contact.fullName,
      address: contact.address,
      age: contact.age,
      phoneNumber: contact.phoneNumber,
      email: contact.email,
      occupation: contact.occupation,
      feedback: contact.feedback,
    };

    setEditFormData(formValues);
  };

  const handleCancelClick = () => {
    setEditContactId(null);
  };

  const handleDeleteClick = (contactId) => {
    const newContacts = [...contacts];

    const index = contacts.findIndex((contact) => contact.id === contactId);

    newContacts.splice(index, 1);

    setContacts(newContacts);
  };

  return (
    <div className="app-container">
      <h1 align="center">FEEDBACK FORM</h1>
      <form onSubmit={handleEditFormSubmit}>
        <table border="2">
          <thead>
            <tr>
              <th>Name</th>
              <th>Address</th>
              <th>Age</th>
              <th>Phone Number</th>
              <th>Email</th>
              <th>Occupation</th>
              <th>Feedback</th>
              <th>Actions</th>
            </tr>
          </thead>
          <tbody>
            {contacts.map((contact) => (
              <Fragment>
                {editContactId === contact.id ? (
                  <EditableRow
                    editFormData={editFormData}
                    handleEditFormChange={handleEditFormChange}
                    handleCancelClick={handleCancelClick}
                  />
                ) : (
                  <ReadOnlyRow
                    contact={contact}
                    handleEditClick={handleEditClick}
                    handleDeleteClick={handleDeleteClick}
                  />
                )}
              </Fragment>
            ))}
          </tbody>
        </table>
      </form>
      <form onSubmit={handleAddFormSubmit}>
        <input
          type="text"
          name="fullName"
          required="required"
          placeholder="Enter a name..."
          onChange={handleAddFormChange}
        />
        <input
          type="text"
          name="address"
          required="required"
          placeholder="Enter an address..."
          onChange={handleAddFormChange}
        />
        <input
          type="text"
          name="age"
          required="required"
          placeholder="Enter your age..."
          onChange={handleAddFormChange}
        />
        <input
          type="text"
          name="phoneNumber"
          required="required"
          placeholder="Enter a phone number..."
          onChange={handleAddFormChange}
        />
        <input
          type="email"
          name="email"
          required="required"
          placeholder="Enter an email..."
          onChange={handleAddFormChange}
        />
        <input
          type="text"
          name="occupation"
          required="required"
          placeholder="Enter your occupation..."
          onChange={handleAddFormChange}
        />
        <input
          type="text"
          name="feedback"
          required="required"
          placeholder="Give your feedback..."
          onChange={handleAddFormChange}
        />
        <button type="reset" onClick={() =>{
          reset ();
        }}>Reset</button>
        <button type="submit">Submit</button>
      </form>
    </div>
  );
};

export default App;
