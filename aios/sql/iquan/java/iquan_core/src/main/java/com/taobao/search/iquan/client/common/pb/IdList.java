// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: iquan.proto

package com.taobao.search.iquan.client.common.pb;

/**
 * Protobuf type {@code iquan.pb.IdList}
 */
public  final class IdList extends
    com.google.protobuf.GeneratedMessageV3 implements
    // @@protoc_insertion_point(message_implements:iquan.pb.IdList)
    IdListOrBuilder {
private static final long serialVersionUID = 0L;
  // Use IdList.newBuilder() to construct.
  private IdList(com.google.protobuf.GeneratedMessageV3.Builder<?> builder) {
    super(builder);
  }
  private IdList() {
    ids_ = emptyIntList();
  }

  @java.lang.Override
  @SuppressWarnings({"unused"})
  protected java.lang.Object newInstance(
      UnusedPrivateParameter unused) {
    return new IdList();
  }

  @java.lang.Override
  public final com.google.protobuf.UnknownFieldSet
  getUnknownFields() {
    return this.unknownFields;
  }
  private IdList(
      com.google.protobuf.CodedInputStream input,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws com.google.protobuf.InvalidProtocolBufferException {
    this();
    if (extensionRegistry == null) {
      throw new java.lang.NullPointerException();
    }
    int mutable_bitField0_ = 0;
    com.google.protobuf.UnknownFieldSet.Builder unknownFields =
        com.google.protobuf.UnknownFieldSet.newBuilder();
    try {
      boolean done = false;
      while (!done) {
        int tag = input.readTag();
        switch (tag) {
          case 0:
            done = true;
            break;
          case 8: {
            if (!((mutable_bitField0_ & 0x00000001) != 0)) {
              ids_ = newIntList();
              mutable_bitField0_ |= 0x00000001;
            }
            ids_.addInt(input.readInt32());
            break;
          }
          case 10: {
            int length = input.readRawVarint32();
            int limit = input.pushLimit(length);
            if (!((mutable_bitField0_ & 0x00000001) != 0) && input.getBytesUntilLimit() > 0) {
              ids_ = newIntList();
              mutable_bitField0_ |= 0x00000001;
            }
            while (input.getBytesUntilLimit() > 0) {
              ids_.addInt(input.readInt32());
            }
            input.popLimit(limit);
            break;
          }
          default: {
            if (!parseUnknownField(
                input, unknownFields, extensionRegistry, tag)) {
              done = true;
            }
            break;
          }
        }
      }
    } catch (com.google.protobuf.InvalidProtocolBufferException e) {
      throw e.setUnfinishedMessage(this);
    } catch (java.io.IOException e) {
      throw new com.google.protobuf.InvalidProtocolBufferException(
          e).setUnfinishedMessage(this);
    } finally {
      if (((mutable_bitField0_ & 0x00000001) != 0)) {
        ids_.makeImmutable(); // C
      }
      this.unknownFields = unknownFields.build();
      makeExtensionsImmutable();
    }
  }
  public static final com.google.protobuf.Descriptors.Descriptor
      getDescriptor() {
    return com.taobao.search.iquan.client.common.pb.Iquan.internal_static_iquan_pb_IdList_descriptor;
  }

  @java.lang.Override
  protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internalGetFieldAccessorTable() {
    return com.taobao.search.iquan.client.common.pb.Iquan.internal_static_iquan_pb_IdList_fieldAccessorTable
        .ensureFieldAccessorsInitialized(
            com.taobao.search.iquan.client.common.pb.IdList.class, com.taobao.search.iquan.client.common.pb.IdList.Builder.class);
  }

  public static final int IDS_FIELD_NUMBER = 1;
  private com.google.protobuf.Internal.IntList ids_;
  /**
   * <code>repeated int32 ids = 1;</code>
   */
  public java.util.List<java.lang.Integer>
      getIdsList() {
    return ids_;
  }
  /**
   * <code>repeated int32 ids = 1;</code>
   */
  public int getIdsCount() {
    return ids_.size();
  }
  /**
   * <code>repeated int32 ids = 1;</code>
   */
  public int getIds(int index) {
    return ids_.getInt(index);
  }
  private int idsMemoizedSerializedSize = -1;

  private byte memoizedIsInitialized = -1;
  @java.lang.Override
  public final boolean isInitialized() {
    byte isInitialized = memoizedIsInitialized;
    if (isInitialized == 1) return true;
    if (isInitialized == 0) return false;

    memoizedIsInitialized = 1;
    return true;
  }

  @java.lang.Override
  public void writeTo(com.google.protobuf.CodedOutputStream output)
                      throws java.io.IOException {
    getSerializedSize();
    if (getIdsList().size() > 0) {
      output.writeUInt32NoTag(10);
      output.writeUInt32NoTag(idsMemoizedSerializedSize);
    }
    for (int i = 0; i < ids_.size(); i++) {
      output.writeInt32NoTag(ids_.getInt(i));
    }
    unknownFields.writeTo(output);
  }

  @java.lang.Override
  public int getSerializedSize() {
    int size = memoizedSize;
    if (size != -1) return size;

    size = 0;
    {
      int dataSize = 0;
      for (int i = 0; i < ids_.size(); i++) {
        dataSize += com.google.protobuf.CodedOutputStream
          .computeInt32SizeNoTag(ids_.getInt(i));
      }
      size += dataSize;
      if (!getIdsList().isEmpty()) {
        size += 1;
        size += com.google.protobuf.CodedOutputStream
            .computeInt32SizeNoTag(dataSize);
      }
      idsMemoizedSerializedSize = dataSize;
    }
    size += unknownFields.getSerializedSize();
    memoizedSize = size;
    return size;
  }

  @java.lang.Override
  public boolean equals(final java.lang.Object obj) {
    if (obj == this) {
     return true;
    }
    if (!(obj instanceof com.taobao.search.iquan.client.common.pb.IdList)) {
      return super.equals(obj);
    }
    com.taobao.search.iquan.client.common.pb.IdList other = (com.taobao.search.iquan.client.common.pb.IdList) obj;

    if (!getIdsList()
        .equals(other.getIdsList())) return false;
    if (!unknownFields.equals(other.unknownFields)) return false;
    return true;
  }

  @java.lang.Override
  public int hashCode() {
    if (memoizedHashCode != 0) {
      return memoizedHashCode;
    }
    int hash = 41;
    hash = (19 * hash) + getDescriptor().hashCode();
    if (getIdsCount() > 0) {
      hash = (37 * hash) + IDS_FIELD_NUMBER;
      hash = (53 * hash) + getIdsList().hashCode();
    }
    hash = (29 * hash) + unknownFields.hashCode();
    memoizedHashCode = hash;
    return hash;
  }

  public static com.taobao.search.iquan.client.common.pb.IdList parseFrom(
      java.nio.ByteBuffer data)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data);
  }
  public static com.taobao.search.iquan.client.common.pb.IdList parseFrom(
      java.nio.ByteBuffer data,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data, extensionRegistry);
  }
  public static com.taobao.search.iquan.client.common.pb.IdList parseFrom(
      com.google.protobuf.ByteString data)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data);
  }
  public static com.taobao.search.iquan.client.common.pb.IdList parseFrom(
      com.google.protobuf.ByteString data,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data, extensionRegistry);
  }
  public static com.taobao.search.iquan.client.common.pb.IdList parseFrom(byte[] data)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data);
  }
  public static com.taobao.search.iquan.client.common.pb.IdList parseFrom(
      byte[] data,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data, extensionRegistry);
  }
  public static com.taobao.search.iquan.client.common.pb.IdList parseFrom(java.io.InputStream input)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseWithIOException(PARSER, input);
  }
  public static com.taobao.search.iquan.client.common.pb.IdList parseFrom(
      java.io.InputStream input,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseWithIOException(PARSER, input, extensionRegistry);
  }
  public static com.taobao.search.iquan.client.common.pb.IdList parseDelimitedFrom(java.io.InputStream input)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseDelimitedWithIOException(PARSER, input);
  }
  public static com.taobao.search.iquan.client.common.pb.IdList parseDelimitedFrom(
      java.io.InputStream input,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseDelimitedWithIOException(PARSER, input, extensionRegistry);
  }
  public static com.taobao.search.iquan.client.common.pb.IdList parseFrom(
      com.google.protobuf.CodedInputStream input)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseWithIOException(PARSER, input);
  }
  public static com.taobao.search.iquan.client.common.pb.IdList parseFrom(
      com.google.protobuf.CodedInputStream input,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseWithIOException(PARSER, input, extensionRegistry);
  }

  @java.lang.Override
  public Builder newBuilderForType() { return newBuilder(); }
  public static Builder newBuilder() {
    return DEFAULT_INSTANCE.toBuilder();
  }
  public static Builder newBuilder(com.taobao.search.iquan.client.common.pb.IdList prototype) {
    return DEFAULT_INSTANCE.toBuilder().mergeFrom(prototype);
  }
  @java.lang.Override
  public Builder toBuilder() {
    return this == DEFAULT_INSTANCE
        ? new Builder() : new Builder().mergeFrom(this);
  }

  @java.lang.Override
  protected Builder newBuilderForType(
      com.google.protobuf.GeneratedMessageV3.BuilderParent parent) {
    Builder builder = new Builder(parent);
    return builder;
  }
  /**
   * Protobuf type {@code iquan.pb.IdList}
   */
  public static final class Builder extends
      com.google.protobuf.GeneratedMessageV3.Builder<Builder> implements
      // @@protoc_insertion_point(builder_implements:iquan.pb.IdList)
      com.taobao.search.iquan.client.common.pb.IdListOrBuilder {
    public static final com.google.protobuf.Descriptors.Descriptor
        getDescriptor() {
      return com.taobao.search.iquan.client.common.pb.Iquan.internal_static_iquan_pb_IdList_descriptor;
    }

    @java.lang.Override
    protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return com.taobao.search.iquan.client.common.pb.Iquan.internal_static_iquan_pb_IdList_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              com.taobao.search.iquan.client.common.pb.IdList.class, com.taobao.search.iquan.client.common.pb.IdList.Builder.class);
    }

    // Construct using com.taobao.search.iquan.client.common.pb.IdList.newBuilder()
    private Builder() {
      maybeForceBuilderInitialization();
    }

    private Builder(
        com.google.protobuf.GeneratedMessageV3.BuilderParent parent) {
      super(parent);
      maybeForceBuilderInitialization();
    }
    private void maybeForceBuilderInitialization() {
      if (com.google.protobuf.GeneratedMessageV3
              .alwaysUseFieldBuilders) {
      }
    }
    @java.lang.Override
    public Builder clear() {
      super.clear();
      ids_ = emptyIntList();
      bitField0_ = (bitField0_ & ~0x00000001);
      return this;
    }

    @java.lang.Override
    public com.google.protobuf.Descriptors.Descriptor
        getDescriptorForType() {
      return com.taobao.search.iquan.client.common.pb.Iquan.internal_static_iquan_pb_IdList_descriptor;
    }

    @java.lang.Override
    public com.taobao.search.iquan.client.common.pb.IdList getDefaultInstanceForType() {
      return com.taobao.search.iquan.client.common.pb.IdList.getDefaultInstance();
    }

    @java.lang.Override
    public com.taobao.search.iquan.client.common.pb.IdList build() {
      com.taobao.search.iquan.client.common.pb.IdList result = buildPartial();
      if (!result.isInitialized()) {
        throw newUninitializedMessageException(result);
      }
      return result;
    }

    @java.lang.Override
    public com.taobao.search.iquan.client.common.pb.IdList buildPartial() {
      com.taobao.search.iquan.client.common.pb.IdList result = new com.taobao.search.iquan.client.common.pb.IdList(this);
      int from_bitField0_ = bitField0_;
      if (((bitField0_ & 0x00000001) != 0)) {
        ids_.makeImmutable();
        bitField0_ = (bitField0_ & ~0x00000001);
      }
      result.ids_ = ids_;
      onBuilt();
      return result;
    }

    @java.lang.Override
    public Builder clone() {
      return super.clone();
    }
    @java.lang.Override
    public Builder setField(
        com.google.protobuf.Descriptors.FieldDescriptor field,
        java.lang.Object value) {
      return super.setField(field, value);
    }
    @java.lang.Override
    public Builder clearField(
        com.google.protobuf.Descriptors.FieldDescriptor field) {
      return super.clearField(field);
    }
    @java.lang.Override
    public Builder clearOneof(
        com.google.protobuf.Descriptors.OneofDescriptor oneof) {
      return super.clearOneof(oneof);
    }
    @java.lang.Override
    public Builder setRepeatedField(
        com.google.protobuf.Descriptors.FieldDescriptor field,
        int index, java.lang.Object value) {
      return super.setRepeatedField(field, index, value);
    }
    @java.lang.Override
    public Builder addRepeatedField(
        com.google.protobuf.Descriptors.FieldDescriptor field,
        java.lang.Object value) {
      return super.addRepeatedField(field, value);
    }
    @java.lang.Override
    public Builder mergeFrom(com.google.protobuf.Message other) {
      if (other instanceof com.taobao.search.iquan.client.common.pb.IdList) {
        return mergeFrom((com.taobao.search.iquan.client.common.pb.IdList)other);
      } else {
        super.mergeFrom(other);
        return this;
      }
    }

    public Builder mergeFrom(com.taobao.search.iquan.client.common.pb.IdList other) {
      if (other == com.taobao.search.iquan.client.common.pb.IdList.getDefaultInstance()) return this;
      if (!other.ids_.isEmpty()) {
        if (ids_.isEmpty()) {
          ids_ = other.ids_;
          bitField0_ = (bitField0_ & ~0x00000001);
        } else {
          ensureIdsIsMutable();
          ids_.addAll(other.ids_);
        }
        onChanged();
      }
      this.mergeUnknownFields(other.unknownFields);
      onChanged();
      return this;
    }

    @java.lang.Override
    public final boolean isInitialized() {
      return true;
    }

    @java.lang.Override
    public Builder mergeFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      com.taobao.search.iquan.client.common.pb.IdList parsedMessage = null;
      try {
        parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
      } catch (com.google.protobuf.InvalidProtocolBufferException e) {
        parsedMessage = (com.taobao.search.iquan.client.common.pb.IdList) e.getUnfinishedMessage();
        throw e.unwrapIOException();
      } finally {
        if (parsedMessage != null) {
          mergeFrom(parsedMessage);
        }
      }
      return this;
    }
    private int bitField0_;

    private com.google.protobuf.Internal.IntList ids_ = emptyIntList();
    private void ensureIdsIsMutable() {
      if (!((bitField0_ & 0x00000001) != 0)) {
        ids_ = mutableCopy(ids_);
        bitField0_ |= 0x00000001;
       }
    }
    /**
     * <code>repeated int32 ids = 1;</code>
     */
    public java.util.List<java.lang.Integer>
        getIdsList() {
      return ((bitField0_ & 0x00000001) != 0) ?
               java.util.Collections.unmodifiableList(ids_) : ids_;
    }
    /**
     * <code>repeated int32 ids = 1;</code>
     */
    public int getIdsCount() {
      return ids_.size();
    }
    /**
     * <code>repeated int32 ids = 1;</code>
     */
    public int getIds(int index) {
      return ids_.getInt(index);
    }
    /**
     * <code>repeated int32 ids = 1;</code>
     */
    public Builder setIds(
        int index, int value) {
      ensureIdsIsMutable();
      ids_.setInt(index, value);
      onChanged();
      return this;
    }
    /**
     * <code>repeated int32 ids = 1;</code>
     */
    public Builder addIds(int value) {
      ensureIdsIsMutable();
      ids_.addInt(value);
      onChanged();
      return this;
    }
    /**
     * <code>repeated int32 ids = 1;</code>
     */
    public Builder addAllIds(
        java.lang.Iterable<? extends java.lang.Integer> values) {
      ensureIdsIsMutable();
      com.google.protobuf.AbstractMessageLite.Builder.addAll(
          values, ids_);
      onChanged();
      return this;
    }
    /**
     * <code>repeated int32 ids = 1;</code>
     */
    public Builder clearIds() {
      ids_ = emptyIntList();
      bitField0_ = (bitField0_ & ~0x00000001);
      onChanged();
      return this;
    }
    @java.lang.Override
    public final Builder setUnknownFields(
        final com.google.protobuf.UnknownFieldSet unknownFields) {
      return super.setUnknownFields(unknownFields);
    }

    @java.lang.Override
    public final Builder mergeUnknownFields(
        final com.google.protobuf.UnknownFieldSet unknownFields) {
      return super.mergeUnknownFields(unknownFields);
    }


    // @@protoc_insertion_point(builder_scope:iquan.pb.IdList)
  }

  // @@protoc_insertion_point(class_scope:iquan.pb.IdList)
  private static final com.taobao.search.iquan.client.common.pb.IdList DEFAULT_INSTANCE;
  static {
    DEFAULT_INSTANCE = new com.taobao.search.iquan.client.common.pb.IdList();
  }

  public static com.taobao.search.iquan.client.common.pb.IdList getDefaultInstance() {
    return DEFAULT_INSTANCE;
  }

  private static final com.google.protobuf.Parser<IdList>
      PARSER = new com.google.protobuf.AbstractParser<IdList>() {
    @java.lang.Override
    public IdList parsePartialFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return new IdList(input, extensionRegistry);
    }
  };

  public static com.google.protobuf.Parser<IdList> parser() {
    return PARSER;
  }

  @java.lang.Override
  public com.google.protobuf.Parser<IdList> getParserForType() {
    return PARSER;
  }

  @java.lang.Override
  public com.taobao.search.iquan.client.common.pb.IdList getDefaultInstanceForType() {
    return DEFAULT_INSTANCE;
  }

}

